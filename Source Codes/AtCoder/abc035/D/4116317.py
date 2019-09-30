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

n,m,t = li()
money = list(li())
graphgo = [[] for _ in range(n)]
graphbk = [[] for _ in range(n)]

for _ in range(m):
    a,b,c = li()
    a -= 1
    b -= 1
    
    graphgo[a].append((c,b))
    graphbk[b].append((c,a))
    
go = dijkstra(graphgo, n, 0)
back = dijkstra(graphbk, n, 0)

ans = money[0]*t
for i in range(1,n):
    if go[i] == float("inf") or back[i] == float("inf"):
        continue
    else:
        ans = max(ans, max(money[0],money[i]) * max(0, t-go[i]-back[i]))

print(ans)