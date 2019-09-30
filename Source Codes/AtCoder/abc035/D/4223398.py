#!/usr/bin/env python3
import scipy.sparse.csgraph as ssc
from scipy.sparse import csr_matrix
N, M, T = map(int, input().split())
A = list(map(int, input().split()))
a = [None] * M
b = [None] * M
c = [None] * M
for i in range(M):
    a[i], b[i], c[i] = map(int, input().split())
    a[i] -= 1
    b[i] -= 1
g = csr_matrix((c, (a, b)), shape=(N, N), dtype=int)
h = csr_matrix((c, (b, a)), shape=(N, N), dtype=int)
ob = ssc.dijkstra(g, indices=0)
ib = ssc.dijkstra(h, indices=0)
ans = 0
for i in range(N):
    ans = max(ans, (T - ob[i] - ib[i]) * A[i])
print(int(ans))