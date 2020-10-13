from cs50 import get_float

while True:
    dollar = get_float("Enter your change: ")
    if not (dollar <= 0):
        break

cents = round(dollar * 100)
coins = 0

while cents >= 25:
    cents -= 25
    coins += 1

while cents >= 10:
    cents -= 10
    coins += 1

while cents >= 5:
    cents -= 5
    coins += 1

while cents >= 1:
    cents -= 1
    coins += 1

print(f"You will need at least {coins} coins\n", end="")
