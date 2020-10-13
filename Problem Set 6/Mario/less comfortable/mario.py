from cs50 import get_int

while True:
    n = get_int("Height: ")
    if not (n < 1 or n > 8):
        break

for i in range(n):
    for j in range(n):
        if i + j < n - 1:
            print(" ", end="")
        else:
            print("#", end="")
    print()
