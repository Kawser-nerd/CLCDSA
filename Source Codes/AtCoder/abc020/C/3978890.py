#!/usr/bin/env python3
import numpy as np
import scipy.sparse.csgraph as ssc
H, W, T = map(int, input().split())
s = [input() for _ in range(H)]


def bfs(x):
    g = np.zeros((H * W, H * W), dtype=np.int32)
    S = None
    G = None
    for i in range(H):
        for j in range(W):
            if s[i][j] == 'S':
                S = i * W + j
            if s[i][j] == 'G':
                G = i * W + j
            if 1 <= i:
                g[i * W + j][(i - 1) * W + j] = x if s[i - 1][j] == '#' else 1
            if i < H - 1:
                g[i * W + j][(i + 1) * W + j] = x if s[i + 1][j] == '#' else 1
            if 1 <= j:
                g[i * W + j][i * W + (j - 1)] = x if s[i][j - 1] == '#' else 1
            if j < W - 1:
                g[i * W + j][i * W + (j + 1)] = x if s[i][j + 1] == '#' else 1

    dist = ssc.dijkstra(g, directed=True, indices=S)

    return dist[G] <= T


ok = 1
ng = T
while abs(ok - ng) > 1:
    m = (ok + ng) // 2
    if bfs(m):
        ok = m
    else:
        ng = m

print(ok)