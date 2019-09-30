import numpy as np
import scipy.sparse.csgraph as spg

N,M = map(int,input().split())
L = list(list(map(int,input().split())) for i in range(M))

matrix = [[float("inf") for x in range(N)] for y in range(N)]

A = []

for i in range(M) :
    u,v,l = L[i]
    u -= 1
    v -= 1
    if u == 0 :
        A.append((v,l))
    else :
        matrix[u][v] = l
        matrix[v][u] = l

shortest_path = spg.floyd_warshall(matrix)

ans = float("inf")

for i in range(len(A)) :
    node_i,cost_i = A[i]
    for j in range(len(A)) :
        if i == j :
            continue
        node_j,cost_j = A[j]
        ans = min(ans, cost_i+cost_j+shortest_path[node_i][node_j])
if ans < float("inf") :
    ans = int(ans)
else :
    ans = -1
print(ans)