S = input()
T = input()

for i in range(len(S)):
    last = S[-1]
    S = last + S[:-1]
    if S == T:
        print('Yes')
        break
else:
    print('No')