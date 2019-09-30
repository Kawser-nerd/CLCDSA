import numpy as np
import scipy.sparse.csgraph as spg

N,M = map(int,input().split())
L = [list(map(int,input().split())) for i in range(M)]

A = np.array([[float("inf")] * N] * N)

B = []

for i in range(M) :
    u,v,l = L[i]
    u -= 1
    v -= 1
    if u == 0 :
        B.append((v,l))
    else :
        A[u,v] = l
        A[v,u] = l
#print(A)
A = spg.floyd_warshall(A)
#print(A)

ans = float("inf")

for i in range(len(B)) :
    for j in range(len(B)) :
        if i == j :
            continue
        n1,d1 = B[i]
        n2,d2 = B[j]
        ans = min(ans, d1+d2+A[n1][n2])    

if not ans < float("inf") :
    ans = -1
else :
    ans = int(ans)
print(ans)