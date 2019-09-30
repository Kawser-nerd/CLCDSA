import numpy as np
from scipy.sparse.csgraph import csgraph_from_dense, dijkstra

INF = 10 ** 20

xs, ys, xt, yt = map(int, input().split())
N = int(input())
X = np.zeros((1, N + 2), dtype=np.float64)
Y = np.zeros((1, N + 2), dtype=np.float64)
R = np.zeros((1, N + 2), dtype=np.float64)

X[0][0] = xs
Y[0][0] = ys
X[0][N + 1] = xt
Y[0][N + 1] = yt

for i in range(N):
    X[0][i + 1], Y[0][i + 1], R[0][i + 1] = map(int, input().split())

# G[i][j]: i??j?????
G = np.maximum(np.sqrt(np.square(X - X.T) + np.square(Y - Y.T)) - (R + R.T),
               np.zeros((N + 2, N + 2), dtype=np.float64))
# ?????inf??????
G += np.diag(np.ones(N + 2, dtype=np.float64) * np.inf)
# ????????
G = csgraph_from_dense(G, null_value=np.inf)
print(dijkstra(G, indices=0)[-1])