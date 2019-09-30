import itertools
import math
from collections import deque
from collections import defaultdict
from itertools import permutations
import heapq
INF = float("inf")

N,M,R = map(int,input().split())
r = list(map(int,input().split()))
adj_cost = defaultdict(set)

for i in range(M):
    a, b, c = map(int, input().split())
    adj_cost[a-1].add((b-1, c))
    adj_cost[b-1].add((a-1, c))

def dijkstra(v):
    d = [INF] * N
    d[v] = 0
    hq =[(0,v)]

    while hq:
        u = heapq.heappop(hq)[1]
        for (v,c) in adj_cost[u]:
            if d[v] > d[u] + c:
                d[v] = d[u] +c
                heapq.heappush(hq,(d[u]+c,v))
    return d

ans = INF
table = {}
for i in r:
    table[i-1] = dijkstra(i-1)

for each in permutations(r):
    dis = 0
    for i in range(R-1):
        dis += table[each[i]-1][each[i+1]-1]

    ans = min(ans,dis)
print(ans)