class Graph:
    def __init__(self, N):
        self.N = N
        self.Edges = [[] for _ in range(self.N)]
        self.rev_Edges = [[] for _ in range(self.N)]
        # N: ???????, self.Edges: ???????????
    def Append_Edge(self, s, t, cost):
        self.Edges[s].append([t, cost])
        self.rev_Edges[t].append([s, cost])
    def Dijkstra(self, s):
        # s: start, return: distance_list
        from heapq import heappush, heappop, heapify
        dist = [10**20 for _ in range(self.N)]
        dist[s], h = 0, []
        heappush(h, [0, s])
        while (len(h)):
            p = heappop(h)
            dv, v = p[0], p[1]
            if dv > dist[v]:
                continue
            for i in range(len(self.Edges[v])):
                u, cost = self.Edges[v][i][0], self.Edges[v][i][1]
                if dv + cost < dist[u]:
                    dist[u] = dv + cost
                    heappush(h, [dist[u], u])
        return dist
    def Rev_Dijkstra(self, s):
        # s: start, return: distance_list
        from heapq import heappush, heappop, heapify
        dist = [10**20 for _ in range(self.N)]
        dist[s], h = 0, []
        heappush(h, [0, s])
        while (len(h)):
            p = heappop(h)
            dv, v = p[0], p[1]
            if dv > dist[v]:
                continue
            for i in range(len(self.rev_Edges[v])):
                u, cost = self.rev_Edges[v][i][0], self.rev_Edges[v][i][1]
                if dv + cost < dist[u]:
                    dist[u] = dv + cost
                    heappush(h, [dist[u], u])
        return dist

N, M, T = map(int, input().split())
A = list(map(int, input().split()))
g = Graph(N)
for _ in range(M):
    a, b, c = map(int, input().split())
    g.Append_Edge(a-1, b-1, c)
dist1, dist2, ans = g.Dijkstra(0), g.Rev_Dijkstra(0), 0
for i in range(N):
    ans = max((T - dist1[i] - dist2[i]) * A[i], ans)
print(ans)