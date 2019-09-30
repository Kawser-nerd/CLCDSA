# encoding: utf-8
import sys
# from collections import deque
import heapq
from scipy.sparse.csgraph import floyd_warshall

input = sys.stdin.readline
inf = 10 ** 18

N, M = map(int, input().split())
uvl = [list(map(int, input().split())) for i in range(M)]

start = []
# tab = [[] for i in range(N)]
d = [[inf] * N for i in range(N)]
for i, (ui, vi, li) in enumerate(uvl):
    if ui == 1:
        start.append((vi, li))
    else:
        # tab[ui - 1].append((vi, li))
        # tab[vi - 1].append((ui, li))
        d[ui - 1][vi - 1] = li
        d[vi - 1][ui - 1] = li

for i in range(1, N): d[i][i] = 0

# print("#", start)
# print("#", tab)
ans = inf

# for k in range(N):
#     for i in range(N):
#         for j in range(N):
#             if i == j or j == k or k == i: continue
#             else:
#                 if d[i][k] + d[k][j] < d[i][j]: d[i][j] = d[i][k] + d[k][j]
d = floyd_warshall(d)

# print("#", d)
for u1, lu in start:
    for v1, lv in start:
        if v1 == u1: continue
        # d = [(0 if i == u1 - 1 else inf) for i in range(N)]
        # prev = [False] * N
        # q = []
        # heapq.heappush(q, (0, u1))
        # while len(q) > 0:
        #     cost, hi = heapq.heappop(q)
        #     if cost >= ans: continue
        #     for hj, lj in tab[hi - 1]:
        #         if hj == prev[hi - 1]: continue
        #         alt = d[hi - 1] + lj
        #         if alt < d[hj - 1]:
        #             d[hj - 1] = alt
        #             prev[hj - 1] = hi
        #             heapq.heappush(q, (alt, hj))
        tmp = lu + lv + int(d[u1 - 1][v1 - 1])
        if tmp < ans: ans = tmp
                            
if ans == inf: print(-1)
else: print(ans)