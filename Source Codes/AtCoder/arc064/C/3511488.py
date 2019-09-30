from math import sqrt
from heapq import heappush, heappop

INF = float('inf')

# ?????????????????????
def Dijkstra(barriers, vSt):
    numV = len(barriers)
    rests = set(range(numV))
    costs = [INF] * numV
    costs[vSt] = 0
    PQ = []
    heappush(PQ, (0, vSt))

    while PQ:
        c, vNow = heappop(PQ)
        if c > costs[vNow]: continue

        rests.remove(vNow)
        if not rests: break

        costNow = c
        xi, yi, ri = barriers[vNow]
        for v2 in rests:
            xj, yj, rj = barriers[v2]
            wt = sqrt((xj - xi) ** 2 + (yj - yi) ** 2) - ri - rj
            if wt < 0: wt = 0
            c2 = costNow + wt
            if c2 < costs[v2]:
                costs[v2] = c2
                heappush(PQ, (c2, v2))

    return costs


xs, ys, xt, yt = map(int, input().split())
N = int(input())
barriers = [(xs, ys, 0), (xt, yt, 0)] + [tuple(map(int, input().split())) for _ in range(N)]

costs = Dijkstra(barriers, 0)
print(costs[1])