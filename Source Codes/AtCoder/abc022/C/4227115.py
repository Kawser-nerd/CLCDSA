from itertools import combinations
from scipy.sparse.csgraph import floyd_warshall
# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

# -*- coding: utf-8 -*-


N, M = map(int, input().split())

ans = float('inf')
adj_0 = []
mat = [[float('inf')]*N for _ in range(N)]
for _ in range(M):
    s, g, w = map(int, input().split())
    if s == 1:
        adj_0.append([g-1, w])
    elif g == 1:
        adj_0.append([s-1, w])
    else:
        mat[s-1][g-1] = w
        mat[g-1][s-1] = w


# for k in range(N):
 #   for i in range(N):
  #      for j in range(N):
   #         mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j])
mat = floyd_warshall(mat, directed=False)

comb = combinations(adj_0, 2)
for p1, p2 in comb:
    ans = min(ans, p1[1]+p2[1]+mat[p1[0]][p2[0]])
if ans == float('inf'):
    ans = -1
    print(ans)
else:
    print(int(ans))