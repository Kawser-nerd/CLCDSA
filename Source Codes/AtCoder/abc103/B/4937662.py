S = list(input())
T = list(input())
n = len(S)
for i in range(n):
    if S == T:
        print('Yes')
        exit()
    string = S[-1]
    S.insert(0, string)
    del S[-1]
print('No')