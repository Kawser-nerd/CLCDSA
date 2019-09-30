import sys
stdin = sys.stdin
 
sys.setrecursionlimit(10**5) 
 
def li(): return map(int, stdin.readline().split())
def li_(): return map(lambda x: int(x)-1, stdin.readline().split())
def lf(): return map(float, stdin.readline().split())
def ls(): return stdin.readline().split()
def ns(): return stdin.readline().rstrip()
def lc(): return list(ns())
def ni(): return int(stdin.readline())
def nf(): return float(stdin.readline())


from functools import reduce
from itertools import permutations

from heapq import heappush, heappop

def dijkstra(graph:list, node:int, start:int) -> list:
    # ??????????INF
    INF = float("inf")
    dist = [INF]*node
    
    # ?????????0???dfs????priority que???
    dist[start] = 0
    heap = [(0,start)]
    
    # ????????priority queue????
    while heap:
        cost, cur_node = heappop(heap)
        
        for nex_cost, nex_node in graph[cur_node]:
            dist_cand = dist[cur_node] + nex_cost
            if dist_cand < dist[nex_node]:
                dist[nex_node] = dist_cand
                heappush(heap, (dist[nex_node], nex_node))
    
    return dist

def find_dist(fr: int, to: int):
    return graph[fr][to]

n,m,rn = li()
r = list(li_())
adj_list = [[] for _ in range(n)]
for _ in range(m):
    a,b,c = li()
    a -= 1
    b -= 1
    adj_list[a].append((c, b))
    adj_list[b].append((c, a))
    
graph = [[0]*rn for _ in range(rn)]
for i, ri in enumerate(r):
    dist = dijkstra(adj_list, n, ri)
    for j, rj in enumerate(r):
        graph[i][j] = dist[rj]

ans = float('inf')
for route in permutations(range(len(r)), len(r)):
    cand = 0
    for i,j in zip(route[:-1], route[1:]):
        cand += graph[i][j]
    
    ans = min(ans, cand)

print(ans)