from cs50 import get_string

text = get_string("Text: ")

letters = 0
count_spaces = 0
count_sentences = 0
spaces = [" "]
sentences = ["!", "?", "."]

for i in range(len(text)):
    if text[i].isalpha():
        letters += 1

for i in range(len(text)):
    for j in range(len(spaces)):
        if text[i] == spaces[j]:
            count_spaces += 1

words = count_spaces + 1

for i in range(len(text)):
    for k in range(len(sentences)):
        if text[i] == sentences[k]:
            count_sentences += 1

L = letters / words * 100
S = count_sentences / words * 100

index = (0.0588 * L) - (0.296 * S) - 15.8
rounded_index = int(round(index))

if rounded_index >= 16:
    print("Grade 16+\n", end="")

elif rounded_index < 1:
    print("Before Grade 1\n", end="")

else:
    print(f"Grade {rounded_index}\n", end="")
