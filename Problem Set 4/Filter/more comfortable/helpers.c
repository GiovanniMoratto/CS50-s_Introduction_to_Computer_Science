#include "helpers.h"
#include <math.h>
#include <cs50.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            int average = round((pixel.rgbtRed + pixel.rgbtGreen + pixel.rgbtBlue) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }
    return;
}

int cap(int value)
{
    return value > 255 ? 255 : value;
}

void swap(RGBTRIPLE *pixel1, RGBTRIPLE *pixel2)
{
    RGBTRIPLE temp = *pixel1;
    *pixel1 = *pixel2;
    *pixel2 = temp;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            swap(&image[i][j], &image[i][width - 1 - j]);
        }
    }

    return;
}

bool is_valuid_pixel(int i, int j, int height, int width)
{
    return i >= 0 && i < height && j >= 0 && j < width;
}

RGBTRIPLE get_blurred_pixel(int i, int j, int height, int width, RGBTRIPLE image[height][width])
{
    int redValue, greenValue, blueValue;
    redValue = greenValue = blueValue = 0;
    int numbOfValidPixels = 0;

    for (int di = -1; di <= 1; di++)
    {
        for (int dj = -1; dj <= 1; dj++)
        {
            int new_i = i + di;
            int new_j = j + dj;
            if (is_valuid_pixel(new_i, new_j, height, width))
            {
                numbOfValidPixels++;
                redValue += image[new_i][new_j].rgbtRed;
                greenValue += image[new_i][new_j].rgbtGreen;
                blueValue += image[new_i][new_j].rgbtBlue;
            }
        }
    }
    RGBTRIPLE blurred_pixel;
    blurred_pixel.rgbtRed = round((float) redValue / numbOfValidPixels);
    blurred_pixel.rgbtGreen = round((float) greenValue / numbOfValidPixels);
    blurred_pixel.rgbtBlue = round((float) blueValue / numbOfValidPixels);

    return blurred_pixel;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_image[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            new_image[i][j] = get_blurred_pixel(i, j, height, width, image);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = new_image[i][j];
        }
    }

    return;
}

RGBTRIPLE get_edged_pixel(int i, int j, int height, int width, RGBTRIPLE image[height][width])
{
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    
    int redValueX, greenValueX, blueValueX, redValueY, greenValueY, blueValueY;
    redValueX = greenValueX = blueValueX = redValueY = greenValueY = blueValueY = 0;
    
    for (int di = -1; di <= 1; di++)
    {
        for (int dj = -1; dj <= 1; dj++)
        {
            if (is_valuid_pixel(i + di, j + dj, height, width))
            {
                int weightX = Gx[di + 1][dj + 1];
                redValueX += weightX * image[i + di][j + dj].rgbtRed;
                greenValueX += weightX * image[i + di][j + dj].rgbtGreen;
                blueValueX += weightX * image[i + di][j + dj].rgbtBlue;
                
                int weightY = Gy[di + 1][dj + 1];
                redValueY += weightY * image[i + di][j + dj].rgbtRed;
                greenValueY += weightY * image[i + di][j + dj].rgbtGreen;
                blueValueY += weightY * image[i + di][j + dj].rgbtBlue;
            }
        }
    }
    RGBTRIPLE pixel;
    pixel.rgbtRed = cap(round(sqrt(redValueX * redValueX + redValueY * redValueY)));
    pixel.rgbtGreen = cap(round(sqrt(greenValueX * greenValueX + greenValueY * greenValueY)));
    pixel.rgbtBlue = cap(round(sqrt(blueValueX * blueValueX + blueValueY * blueValueY)));
    
    return pixel;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_image[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            new_image[i][j] = get_edged_pixel(i, j, height, width, image);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = new_image[i][j];
        }
    }
    
    return;
}
