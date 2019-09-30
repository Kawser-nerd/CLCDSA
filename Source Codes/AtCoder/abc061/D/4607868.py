from collections import defaultdict
from heapq import heappop, heappush

class Graph(object):

    def __init__(self):
        self.graph = defaultdict(list)

    def __len__(self):
        return len(self.graph)

    def add_edge(self, a, b, w):
        self.graph[a].append((b, w))

    def get_nodes(self):
        return self.graph.keys()


class Dijkstra(object):
    def __init__(self, graph, s):
        self.g = graph.graph
        self.dist = defaultdict(lambda: -float('inf'))
        self.dist[s] = 0
        self.prev = defaultdict(lambda: None)
        self.x = 0
        self.y = 0

        self.Q = []
        heappush(self.Q, (self.dist[s], s))

        c = 0
        while self.Q:
            c += 1
            dist_u, u = heappop(self.Q)
            if self.dist[u] < dist_u:
                continue
            for v, w in self.g[u]:
                alt = dist_u + w
                if self.dist[v] < alt:
                    self.dist[v] = alt
                    self.prev[v] = u
                    heappush(self.Q, (alt, v))
            if c == 2100:
                self.x = self.dist[N]
            if c >= 200000:
                self.y = self.dist[N]
                break
    def s_d(self, goal):
        return self.dist[goal]

    def s_p(self, goal):
        path = []
        node = goal
        while node is not None:
            path.append(node)
            node = self.prev[node]
        return path[::-1]

N, M = list(map(int, input().split()))

g_a = Graph()
for i in range(M):
    a, b, w = list(map(int, input().split()))
    g_a.add_edge(a, b, w)

s = 1
d_a = Dijkstra(g_a, s)

if d_a.x == d_a.y:
    print(d_a.dist[N])
else:
    print("inf")