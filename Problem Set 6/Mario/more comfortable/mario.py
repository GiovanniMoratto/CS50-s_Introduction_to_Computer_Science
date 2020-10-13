from cs50 import get_int

while True:
    n = get_int("Height: ")
    if not (n < 1 or n > 8):
        break

for i in range(n):
    for j in range(n - i - 1):
        print(" ", end="")
    
    for column1 in range(-1, i):
        print("#", end="")
    
    print("  ", end="")
    
    for column2 in range(-1, i):
        print("#", end="")
        
    print()
