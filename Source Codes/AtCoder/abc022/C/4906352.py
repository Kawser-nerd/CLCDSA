from scipy.sparse import csr_matrix
from scipy.sparse.csgraph import floyd_warshall
from itertools import combinations

n, m = map(int, input().split())

d = [[float('inf') for _ in range(n-1)] for _ in range(n-1)]

s = []
p = [0] * (n-1)

for i in range(m):
    a, b, c = map(int, input().split())
    a -= 2
    b -= 2
    if a < 0:
        s.append(b)
        p[b] = c
    else:
        d[a][b] = c
        d[b][a] = c

for i in range(n-1):
    d[i][i] = 0

d = floyd_warshall(csgraph=d, directed=False, return_predecessors=False)

ans = float('inf')
for i, j in combinations(s, 2):
    x = d[i][j]
    if x != float('inf'):
        ans = min(int(x) + p[i] + p[j], ans)

if ans == float('inf'):
    print(-1)
else:
    print(ans)