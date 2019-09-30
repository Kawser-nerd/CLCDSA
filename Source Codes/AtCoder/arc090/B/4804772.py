import itertools
import math
from collections import deque
from collections import defaultdict
from itertools import permutations
import heapq
import bisect
from scipy.sparse.csgraph import floyd_warshall as wf
INF = float("inf")


N,M = map(int,input().split())
Adj_list = defaultdict(set)

for i in range(M):
    a, b, c = map(int, input().split())
    Adj_list[a-1].add((b-1, c))
    Adj_list[b-1].add((a-1, -c))
visited =[None]*(N)
ok = True
stack = []
for x in range(N):
   if visited[x] is not None:continue
   visited[x] = 0
   stack = [x]
   while stack:
       v = stack.pop()
       for to,d in Adj_list[v]:
           if visited[to] is None:
               visited[to] = visited[v] + d
               stack.append(to)
           else:
               if visited[to] != visited[v]+d:
                   ok = False
                   break
   if ok == False:
        break
print("Yes" if ok else "No")