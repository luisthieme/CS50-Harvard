def main():
    card_number = input("Enter card number: ")
    length = len(card_number)
    x = 0
    normal_sum = 0
    multiplied_sum = 0

    while x < length:
        last_digit = int(card_number[length - x - 1])
        normal_sum += last_digit
        if length - x - 2 >= 0:
            sec_to_last_digit = int(card_number[length - x - 2])
            sec_to_last_digit *= 2
            multiplied_sum += digit_sum(sec_to_last_digit)
        x += 2
    if (normal_sum + multiplied_sum) % 10 == 0:
        get_provider(card_number)
    else:
        print("INVALID")


def digit_sum(number):
    sum = 0
    while number > 0:
        sum += number % 10
        number //= 10
    return sum


def get_provider(card_number):
    if int(card_number[0]) == 3 and (int(card_number[1]) == 4 or int(card_number[1]) == 7):
        print("AMEX")
    elif int(card_number[0]) == 4:
        print("VISA")
    else:
        print("MASTERCARD")

main()    

    
