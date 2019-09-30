from collections import Counter
import heapq
h, w = [int(item) for item in input().split()]
c = [[int(item) for item in input().split()] for _ in range(10)]
a = [[int(item) for item in input().split()] for _ in range(h)]
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

dijk = Dijkstra(c)
costs = [0] * 10
for i in range(10):
    costs[i] = dijk.calc(i)[1]
    dijk.reset()

count = Counter()
for item in a:
    count.update(item)

ans = 0
for key in count.keys():
    if key >= 0:
        ans += count[key] * costs[key]

print(ans)