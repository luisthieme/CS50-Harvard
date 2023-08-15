while True:
    try:
        change_owed = float(input("Change owed: "))
        if change_owed > 0:
            break
    except ValueError:
        print("not a valid amount.")

counter = 0

while change_owed > 0:
    if change_owed >= 0.25:
        counter += 1
        change_owed -= 0.25
        continue
    elif change_owed >= 0.10:
        counter += 1
        change_owed -= 0.10
        continue
    elif change_owed >= 0.05:
        counter += 1
        change_owed -= 0.05
        continue
    else:
        counter += 1
        change_owed -= 0.01

print(counter)
        

        