S = input()
number = 0
for i in range(len(S)):
    if S[i] == "+":
        number += 1
    else:
        number -= 1
print(number)