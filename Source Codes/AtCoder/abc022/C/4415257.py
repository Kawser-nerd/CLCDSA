import numpy as np
from scipy.sparse.csgraph import floyd_warshall as wf
from itertools import combinations
import sys
inp = sys.stdin.readline

x = 10**9
N, M = map(int,inp().split())
D = np.zeros(N) + x
K = np.zeros((N, N)) + x
for _ in range(M):
  u, v, l = map(int,inp().split())
  u -= 1
  v -= 1
  if(0 in (u, v)):
    D[u+v] = l
  else:
    K[u, v] = K[v, u] = l

K = wf(K)
r = min([D[i]+D[j]+K[i,j] for i, j in combinations(range(0, N), 2)])
print(int([-1,r][r<x]))