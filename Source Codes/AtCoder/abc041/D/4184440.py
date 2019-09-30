def inpl(): return list(map(int, input().split()))

N, M = inpl()
have_edge_to = [0]*N
bipow = [2**i for i in range(N)]

for i in range(M):
    x, y = [a-1 for a in inpl()]
    have_edge_to[y] += bipow[x]

DP = [0]*(2**N)

for i in range(1, 2**N):
    tmp = 0
    for j in range(N):
        S_minus_v = i & ~bipow[j]
        if ((i >> j)&1 == 0) or (have_edge_to[j] & S_minus_v):
            continue
        tmp += DP[S_minus_v]
    DP[i] = max(1, tmp)
print(DP[-1])