from collections import deque

INF = float('inf')

N, K = map(int, input().split())
edges = [list(map(lambda x: int(x) - 1, input().split())) for e in range(N - 1)]

adjL = [[] for v in range(N)]
for a, b in edges:
    adjL[a].append(b)
    adjL[b].append(a)

# ?????VCenter????radius?????????????
def bfs(adjList, VCenter, radius):
    numV = len(adjList)

    dist = [INF] * numV
    for v in VCenter:
        dist[v] = 0

    ans = 0
    Q = deque(VCenter)
    while Q:
        vNow = Q.popleft()
        distNow = dist[vNow]

        if distNow > radius: break
        ans += 1

        for v2 in adjList[vNow]:
            if dist[v2] != INF: continue
            dist[v2] = distNow + 1
            Q.append(v2)

    return ans


# ???????K????????????
if K % 2:
    # K??????????????
    VC = edges
    r = (K - 1) // 2
else:
    # K???????????????
    VC = [[v] for v in range(N)]
    r = K // 2

ans = N
for V in VC:
    num = bfs(adjL, V, r)
    ans = min(ans, N - num)

print(ans)