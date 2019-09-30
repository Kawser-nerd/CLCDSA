S = str(input())
ascii_letters = "abcdefghijklmnopqrstuvwxyz"
for letter in ascii_letters:
    if letter not in S:
        print(letter)
        exit()
print("None")