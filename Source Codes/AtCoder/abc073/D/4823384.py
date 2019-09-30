from scipy.sparse.csgraph import floyd_warshall as wf
import itertools

N, M, R = map(int, input().split())
r = [int(i) for i in input().split()]

G = [[float('inf')] * N for _ in range(N)]
for i in range(N):
    G[i][i] = 0
for _ in range(M):
    i, j, k = map(int, input().split())
    G[i - 1][j - 1] = k
    G[j - 1][i - 1] = k
    
wf = wf(G)

ans = float('inf')
for perm in itertools.permutations(r):
    tmp = 0
    for i in range(len(perm) - 1):
        tmp += wf[perm[i] - 1][perm[i + 1] - 1]
    ans = min(ans, tmp)
    
print(int(ans))