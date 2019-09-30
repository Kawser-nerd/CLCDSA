S = input()

flag = False
for i in range(97,97 + 26):
    c = chr(i)
    if c not in S:
        print(c)
        flag = True
        break

if not flag:
    print("None")