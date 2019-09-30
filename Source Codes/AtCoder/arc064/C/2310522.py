# -*- coding: utf-8 -*-
import numpy as np
from scipy.sparse.csgraph import csgraph_from_dense, dijkstra
def inpl(): return map(int, input().split())

sx, sy, tx, ty = inpl()
N = int(input())
X = np.zeros((1, N+2), dtype=np.float64)
Y = np.zeros((1, N+2), dtype=np.float64)
R = np.zeros((1, N+2), dtype=np.float64)

X[0][0] = sx
Y[0][0] = sy
X[0][N+1] = tx
Y[0][N+1] = ty

for i in range(N):
    X[0][i+1], Y[0][i+1], R[0][i+1] = inpl()

G = np.maximum(np.sqrt(np.square(X-X.T) + np.square(Y-Y.T)) - (R+R.T),
               np.zeros((N+2, N+2), dtype=np.float64)) 
G += np.diag(np.ones(N+2, dtype=np.float64)*np.inf)
G = csgraph_from_dense(G, null_value=np.inf)
print(dijkstra(G, indices=0)[-1])