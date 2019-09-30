import itertools

N, M, Q = list(map(int, input().split()))

route = [[0 for i in range(N+1)] for j in range(N+1)]

for i in range(M):
    L, R = list(map(int, input().split()))
    route[L][R] += 1

for i in range(1, N):
    route[i] = list(itertools.accumulate(route[i]))

for i in range(2, N+1):
    for j in range(1, N+1):
        route[i][j] += route[i-1][j]

for i in range(Q):
    p, q = list(map(int, input().split()))
    print(route[q][q]-route[p-1][q]-route[q][p-1]+route[p-1][p-1])