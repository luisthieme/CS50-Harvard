text = input("Enter text: ")
text += " "

letters = 0
words = 0
sentences = 0

for charakter in text:
    if charakter in [".", "!", "?"]:
        sentences += 1
    elif charakter == " ":
        words += 1
    elif charakter not in ["\'", "\""]:
        letters += 1

L = (letters / words) * 100
S = (sentences / words) * 100
grade = 0.0588 * L - 0.296 * S - 15.8

if grade < 1:
    print("Before Greade 1")
elif grade > 16:
    print("Grade 16+")
else:
    print(f"Grade {grade}")
