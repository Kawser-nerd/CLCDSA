S = input()
T = input()

f = False
for i in range(len(S)):
    if S[-i:]+S[:-i] == T:
        f = True
        break

if f:
    print('Yes')
else:
    print('No')