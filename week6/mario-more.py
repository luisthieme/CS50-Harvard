while True:
    try:
        input = int(input("number or rows: "))
        if input > 0:
            break
    except ValueError or TypeError:
        print("Not a positiv Int")

for x in range(input):
    print(" " * (input - x), end="")
    for y in range(x + 1):
        print("#", end="")
    print(" ", end="")
    for y in range(x + 1):
        print("#", end="")
    print()