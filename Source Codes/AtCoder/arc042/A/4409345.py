N, M = map(int, input().split())
L = [int(input()) for _ in range(M)]
tmp = [N - i for i in range(N)]
for i in range(M):
    if tmp[-1] != L[i]:
        tmp.append(L[i])

flag = [False for _ in range(N)]
for i in range(len(tmp)):
    if flag[tmp[len(tmp)-i-1]-1] == False:
        flag[tmp[len(tmp)-i-1]-1] = True
        print(tmp[len(tmp)-i-1])