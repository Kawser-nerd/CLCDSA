import numpy as np
import scipy.sparse.csgraph as csg

INF = float('inf')

N,M = map(int,input().split())
A = np.array([[INF]*N]*N)

for i in range(M):
    a,b,t = map(int,input().split())
    A[a-1][b-1] = t
    A[b-1][a-1] = t

A = csg.floyd_warshall(A)

Ans = INF
for i in range(N):
    Ans = min(Ans, max(A[i]))

print(int(Ans))