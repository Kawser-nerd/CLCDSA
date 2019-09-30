s = input()
is_inS = [0] * 26
for c in s:
    is_inS[ord(c) - 97] = 1

for i in range(26):
    if is_inS[i] == 0:
        print(chr(i+97))
        exit()
print("None")