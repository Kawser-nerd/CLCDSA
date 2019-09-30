S = input()
A = 0
Z = 0
flg = 0
for i in range(len(S)):
    if S[i] == 'A' and flg == 0:
        A = i
        flg = 1
    if S[i] == 'Z':
        Z = i
print(Z - A + 1)