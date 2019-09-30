A, B = map(int, input().split())
S = list(input())

flag = True
for i in range(len(S)):
    if i == A:
        if S[i] != '-':
            flag=False
    else:
        if S[i] not in '0123456789':
            flag=False

if flag:
    print('Yes')
else:
    print('No')