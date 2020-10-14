from cs50 import get_int
import sys
sys.float_info.max

while True:
    creditCardNumber = get_int("Number: \n")
    if not (creditCardNumber <= 0):
        break

workingCC = creditCardNumber
add = 0
count = 0
divisor = 10

while workingCC > 0:
    lastDigit = int(workingCC % 10)
    add += int(lastDigit)
    workingCC = int(workingCC / 100)

workingCC = int(creditCardNumber / 10)

while workingCC > 0:
    lastDigit = int(workingCC % 10)
    timesTwo = int(lastDigit * 2)

    add += int(((timesTwo % 10) + (timesTwo / 10)))
    workingCC = int(workingCC / 100)

workingCC = creditCardNumber
count = len(str(workingCC))

for i in range(count - 2):
    divisor = divisor * 10

firstDigit = creditCardNumber // divisor
firstTwoDigits = creditCardNumber // (divisor // 10)

if add % 10 == 0:
    if firstDigit == 4 and (count == 13 or count == 16):
        print("VISA\n", end="")

    elif (firstTwoDigits == 34 or firstTwoDigits == 37) and count == 15:
        print("AMEX\n", end="")

    elif (50 < firstTwoDigits and firstTwoDigits < 56) and count == 16:
        print("MASTERCARD\n", end="")

    else:
        print("INVALID\n", end="")

else:
    print("INVALID\n", end="")
