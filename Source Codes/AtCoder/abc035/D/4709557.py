import heapq
N, M, T = map(int, input().split())
A = [int(i) for i in input().split()]

s1 = [[] for _ in range(N)]
s2 = [[] for _ in range(N)]

for i in range(M):
    s, g, c = map(int, input().split())

    s1[s-1].append((g-1, c))
    s2[g-1].append((s-1, c))


INF = 10**9

TT = [T] * N


def dijkstra(S):
    cost = [INF] * N
    cost[0] = 0
    visited = {0}
    hq = [(0, 0)]


    while hq:
        u = heapq.heappop(hq)[1]
        visited.add(u)

        for node, c in S[u]:
            if (node not in visited) and cost[node] > cost[u] + c:
                cost[node] = cost[u] + c
                heapq.heappush(hq, (cost[u] + c, node))

    for i in range(N):
        TT[i] -= cost[i]


dijkstra(s1)
dijkstra(s2)

M = 0
for i in range(N):
    now = TT[i] * A[i]
    if M < now:
        M = now

print(M)