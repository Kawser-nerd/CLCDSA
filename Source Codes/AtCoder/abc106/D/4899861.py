N, M, Q = map(int, input().split())

count = [[0] * (N+1) for _ in range(N+1)]

for i in range(M):
    l, r = map(int, input().split())

    count[l][r] += 1

# 2?????
for i in range(1, N+1):
    for j in range(1, N+1):
        count[i][j] += count[i][j-1]
for i in range(1, N+1):
    for j in range(1, N+1):
        count[i][j] += count[i-1][j]


for i in range(Q):
    l, r = map(int, input().split())
    print(count[r][r]+count[l-1][l-1]-count[l-1][r]-count[r][l-1])