import heapq


class Dijkstra:
    """??????????.0-index"""

    def __init__(self, graph, start_point, goal_point=None):
        """Intialization.

        :param graph:List[Dict[int, int]]
        :param start_point: start index
        :param goal_point: goal index
        """
        node_num = len(graph)
        self.graph = graph
        self.start_point = start_point
        self.goal_point = goal_point
        self.dist = [float("inf") for _ in range(node_num)]
        self.prev = [float("inf") for _ in range(node_num)]

    def run(self):
        self.dist[self.start_point] = 0
        heap_q = []
        heapq.heappush(heap_q, (0, self.start_point))
        while len(heap_q) != 0:
            # priority queue?????????????.
            prev_cost, src = heapq.heappop(heap_q)

            if self.dist[src] < prev_cost:
                continue

            for dest, cost in self.graph[src].items():
                if self.dist[dest] > self.dist[src] + cost:
                    self.dist[dest] = self.dist[src] + cost
                    # priority queue????????????.
                    heapq.heappush(heap_q, (self.dist[dest], dest))
                    self.prev[dest] = src
        if self.goal_point is not None:
            return self.get_path()
        else:
            return self.dist

    def get_path(self):
        path = [self.goal]
        dest = self.goal

        while self.prev[dest] != float("inf"):
            path.append(self.prev[dest])
            dest = self.prev[dest]

        return list(reversed(path))


N = int(input())
graph = [{} for _ in range(N)]
for _ in range(N - 1):
    a, b, c = map(int, input().split())
    graph[a - 1][b - 1] = c
    graph[b - 1][a - 1] = c

Q, K = map(int, input().split())

solver = Dijkstra(graph, K - 1)
d = solver.run()

for _ in range(Q):
    x, y = map(int, input().split())
    print(d[x - 1] + d[y - 1])