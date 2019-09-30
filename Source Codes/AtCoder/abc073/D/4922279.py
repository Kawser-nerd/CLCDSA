import heapq
from itertools import permutations
n, m, r = [int(item) for item in input().split()]
rs = [int(item) for item in input().split()]
abc = [[int(item) for item in input().split()] for _ in range(m)]
INF = 10**9

class Dijkstra:
    def __init__(self, adj):
        self.adj = adj
        self.num = len(adj)
        self.dist = [INF] * self.num
        self.prev = [INF] * self.num
        self.q = []

    def reset(self):
        self.dist = [INF] * self.num
        self.prev = [INF] * self.num
        self.q = []

    def calc(self, start, goal=None):
        self.dist[start] = 0
        heapq.heappush(self.q, (0, start))
        while len(self.q) != 0:
            prov_cost, src = heapq.heappop(self.q)
            if self.dist[src] < prov_cost:
                continue
            for dest in range(self.num):
                cost = self.adj[src][dest]
                if cost != INF and self.dist[dest] > self.dist[src] + cost:
                    self.dist[dest] = self.dist[src] + cost
                    heapq.heappush(self.q, (self.dist[dest], dest))
                    self.prev[dest] = src
        if goal is not None:
            return self.get_path(goal)
        else:
            return self.dist

    def get_path(self, goal):
        path = [goal]
        dest = goal

        while self.prev[dest] != INF:
            path.append(self.prev[dest])
            dest = self.prev[dest]
        return list(reversed(path))

path = [[INF] * n for _ in range(n)]
short_path = [[INF] * n for _ in range(n)]
for i in range(n):
    path[i][i] = 0
for a, b, c in abc:
    path[a-1][b-1] = path[b-1][a-1] = c

dij = Dijkstra(path)
for item in rs:
    for i in range(n):
        short_path[item-1][i] = dij.calc(item-1)[i]
    dij.reset()

ans = INF
for pattern in permutations(rs):
    distance = 0
    for i in range(1,r):
        distance += short_path[pattern[i-1]-1][pattern[i]-1]
    ans = min(ans, distance)
print(ans)