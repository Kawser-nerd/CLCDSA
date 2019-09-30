from collections import defaultdict
from heapq import heappop, heappush

class Graph(object):
    #?????????????
    def __init__(self):
        self.graph = defaultdict(list)

    def __len__(self):
        return len(self.graph)

    def add_edge(self, src, dst, weight=1):
        self.graph[src].append((dst, weight))

    def get_nodes(self):
        return self.graph.keys()

class Dijkstra(object):
    #???????
    #O((E+V)logV)

    def __init__(self, graph, start):
        self.g = graph.graph

        #start?????????
        #start????0, ????????????
        self.dist = defaultdict(lambda:float("inf"))
        self.dist[start] = 0

        #?????1??????
        self.prev = defaultdict(lambda: None)

        #start???????????
        self.Q = []
        heappush(self.Q, (self.dist[start], start))

        while self.Q:
            #?????????????????????
            dist_u, u = heappop(self.Q)

            if self.dist[u] < dist_u:
                continue

            for v, weight in self.g[u]:
                alt = dist_u + weight
                if self.dist[v] > alt:
                    self.dist[v] = alt
                    self.prev[v] = u
                    heappush(self.Q, (alt, v))

    def shortest_distance(self, goal):

        #start?????goal??????????
        return self.dist[goal]

    def shortest_path(self, goal):

        #start?????goal??????????
        path = []
        node = goal
        while node is not None:
            path.append(node)
            node = self.prev[node]

        return path[::-1]

N, M, T = map(int, input().split())
A = list(map(int, input().split()))

g1 = Graph()
g2 = Graph()

for _ in range(M):
    a, b, c = map(int, input().split())
    g1.add_edge(a-1, b-1, c)
    g2.add_edge(b-1, a-1, c)

d1 = Dijkstra(g1, 0)
d2 = Dijkstra(g2, 0)

ans = 0
for i in range(N):
    X = d1.shortest_distance(i) + d2.shortest_distance(i)
    ans = max(ans, A[i]*(T-X))
print(ans)