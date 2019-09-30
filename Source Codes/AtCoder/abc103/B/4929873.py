S = input()
T = input()

for i in range(len(S)):
    if T == S[i:] + S[:i]:
        print('Yes')
        exit()
print('No')