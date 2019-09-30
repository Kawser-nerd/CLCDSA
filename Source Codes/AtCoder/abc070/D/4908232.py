import heapq

N = int(input())
d = [0] * N
INF = float('inf')

class Info:
    def __init__(self, to, cost):
        self.to = to
        self.cost = cost
        
G = [[] for i in range(N)]
for _ in range(N - 1):
    a, b, c = map(int, input().split())
    G[a - 1].append(Info(b - 1, c))
    G[b - 1].append(Info(a - 1, c))
    
def dijkstra(s):
    for i in range(N):
        d[i] = INF
    d[s] = 0
    h = []
    heapq.heappush(h, [0, s])
    
    while h != []:
        p = heapq.heappop(h)
        v = p[1]
        if d[v] < p[0]:
            continue
        for i in range(len(G[v])):
            e = G[v][i]
            if d[e.to] > d[v] + e.cost:
                d[e.to] = d[v] + e.cost
                heapq.heappush(h, [d[e.to], e.to])

Q, K = map(int, input().split())

dijkstra(K - 1)

for _ in range(Q):
    ans = 0
    x, y = map(int, input().split())
    ans += d[x - 1]
    ans += d[y - 1]
    print(ans)