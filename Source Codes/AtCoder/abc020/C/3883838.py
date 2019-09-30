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

def dijkstra(graph: list, hs:int, ws:int, x:int):
    H = len(graph)
    W = len(graph[0])
    dist = [[float("inf") for _ in range(W)] for _ in range(H)]
    dist[hs][ws] = 0
    que = [(dist[hs][ws], (hs,ws))]
    
    dhs = [0,1,0,-1]
    dws = [1,0,-1,0]
    
    while que:
        dcur, (hcur, wcur) = heappop(que)
        
        for dh,dw in zip(dhs,dws):
            if 0<=hcur+dh<H and 0<=wcur+dw<W:
                col = graph[hcur+dh][wcur+dw]
                
                if dist[hcur+dh][wcur+dw] > dcur + (x if col=="#" else 1):
                    dist[hcur+dh][wcur+dw] = dcur + (x if col=="#" else 1)
                    heappush(que, (dist[hcur+dh][wcur+dw], (hcur+dh, wcur+dw)))

    return dist

h,w,t = li()              
graph = [list(ns()) for _ in range(h)]
for hi in range(h):
    for wj in range(w):
        if graph[hi][wj] == "S":
            hs = hi
            ws = wj
        if graph[hi][wj] == "G":
            hg = hi
            wg = wj
            
dist = dijkstra(graph, hs,ws,8)


low = 0
high = 10**9+1

while high-low > 1:
    mid = (high+low)//2
    dist = dijkstra(graph, hs,ws,mid)
    if dist[hg][wg] <= t:
        low = mid
    else:
        high = mid
        
print(low)