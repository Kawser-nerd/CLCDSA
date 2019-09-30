N = int(input())
L = []
for i in range(N):
    L.append(list(input()))

ans = [[0]*N for i in range(N)]
for i in range(N):
    for j in range(N):
        ans[j][N-i-1] = L[i][j]

for i in range(N):
    print(''.join(ans[i]))