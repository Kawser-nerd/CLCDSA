from heapq import heappop, heappush
MOD = 10 ** 9 + 7

N, M = map(int, input().split())
S, T = map(lambda x: int(x) - 1, input().split())

adjList = [[] for i in range(N)]
for i in range(M):
    U, V, D = map(int, input().split())
    adjList[U - 1].append((V - 1, D))
    adjList[V - 1].append((U - 1, D))

# ??S?????????????
numRouteS = [0] * N
numRouteS[S] = 1

cost = [float('inf')] * N
cost[S] = 0
prev = [None] * N
vs = []

pq = []
heappush(pq, (0, S))
while pq:
    c, vNow = heappop(pq)
    if c > cost[vNow]: continue
    if c > cost[T]: break
    vs += [vNow]

    for v2, wt in adjList[vNow]:
        c2 = c + wt
        if c2 < cost[v2]:
            cost[v2] = c2
            prev[v2] = [vNow]
            numRouteS[v2] = numRouteS[vNow]
            heappush(pq, (c2, v2))
        elif c2 == cost[v2]:
            prev[v2] += [vNow]
            numRouteS[v2] = (numRouteS[v2] + numRouteS[vNow]) % MOD

# ??T?????????????
numRouteT = [0] * N
numRouteT[T] = 1
cST = cost[T]
for iV, v in enumerate(reversed(vs)):
    if cost[v] * 2 < cST:
        iVLim = len(vs) - iV
        break
    for v0 in prev[v]:
        numRouteT[v0] = (numRouteT[v0] + numRouteT[v]) % MOD

# ??????????????????????????
ans = (numRouteS[T] ** 2) % MOD

for v in vs[:iVLim]:
    x = (numRouteS[v] ** 2) % MOD
    for v2, wt in adjList[v]:
        if (cost[v2] * 2 > cST) and cost[v] + wt == cost[v2]:
            y = (numRouteT[v2] ** 2) % MOD
            ans = (ans - x * y) % MOD

for v in vs[iVLim:]:
    if cost[v] * 2 > cST: break
    x = (numRouteS[v] ** 2) % MOD
    y = (numRouteT[v] ** 2) % MOD
    ans = (ans - x * y) % MOD

print(ans)