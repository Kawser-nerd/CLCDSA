from collections import defaultdict
from heapq import heappop, heappush

def getlist():
    return list(map(int, input().split()))

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
        self.dist = defaultdict(lambda: float('inf'))
        self.dist[s] = 0
        self.prev = defaultdict(lambda: None)

        self.Q = []
        heappush(self.Q, (self.dist[s], s))

        while self.Q:
            dist_u, u = heappop(self.Q)
            if self.dist[u] < dist_u:
                continue
            for v, w in self.g[u]:
                alt = dist_u + w
                if self.dist[v] > alt:
                    self.dist[v] = alt
                    self.prev[v] = u
                    heappush(self.Q, (alt, v))

    def s_d(self, goal):
        return self.dist[goal]

    def s_p(self, goal):
        path = []
        node = goal
        while node is not None:
            path.append(node)
            node = self.prev[node]
        return path[::-1]

H, W = getlist()
c = []
for i in range(10):
    cl = getlist()
    c.append(cl)
A = []
for i in range(H):
    Al = getlist()
    A.append(Al)

g_a = Graph()
for i in range(10):
    for j in range(10):
        a, b, w = i, j, c[i][j]
        if a != b:
            g_a.add_edge(b, a, w)

d_a = Dijkstra(g_a, 1)

ans = 0
for i in range(H):
    for j in range(W):
        if A[i][j] == -1:
            pass
        else:
            ans += d_a.dist[A[i][j]]

print(ans)