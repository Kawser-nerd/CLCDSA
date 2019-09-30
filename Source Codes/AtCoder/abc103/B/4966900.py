S = input()
T = input()

for i in range(len(S)):
    if S[i:] + S[:i] == T:
        print('Yes')
        quit()
print('No')