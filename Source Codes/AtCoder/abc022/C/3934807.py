#!/usr/bin/env python3
import numpy as np
from scipy.sparse import csr_matrix
from scipy.sparse.csgraph import floyd_warshall
N, M = map(int, input().split())
g = np.zeros((N, N))
inf = float('inf')
for i in range(M):
    u, v, length = map(int, input().split())
    g[u-1, v-1] = length
sg = g.copy()
sg[0][:] = np.zeros(N)
dist = floyd_warshall(csgraph=csr_matrix(sg), directed=False)
ans = inf
for i in range(1, N):
    for j in range(i+1, N):
        if g[0, i] == 0 or g[0, j] == 0:
            continue
        ans = min(ans, g[0, i] + g[0, j] + dist[i][j])
print(int(ans if ans < inf else -1))