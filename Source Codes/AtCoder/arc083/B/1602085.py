N = int(input())

import numpy as np

G = np.array([list(map(int,input().split())) for i in range(N)], dtype=np.uint32)

import scipy.sparse.csgraph as csg

G2 = csg.floyd_warshall(G,directed=False)

if np.any(G != G2):
  print(-1)
else:
  G[G==0] = 2*10**9
  t = 0
  for i in range(N):
    for j in range(i+1,N):
      n = np.min(G[i]+G[j])
      if n > G[i,j]:
        t += G[i,j]


  print(t)