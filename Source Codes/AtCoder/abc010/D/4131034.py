from collections import deque


class Dinic(object):
    __slots__ = ["inf", "v_count", "edges", "iter", "level"]

    def __init__(self, v_count: int, edges: list):
        self.inf = 10**9
        self.v_count = v_count
        self.edges = [[] for _ in [0]*v_count]
        self.iter = [0]*v_count
        self.level = None
        self._create_graph(edges)

    def _create_graph(self, _edges):
        edges = self.edges
        for origin, dest, cap in _edges:
            edges[origin].append([dest, cap, len(edges[dest])])
            edges[dest].append([origin, 0, len(edges[origin])-1])

    def solve(self, source: int, sink: int):
        max_flow = 0

        while True:
            self.bfs(source)
            if self.level[sink] < 0:
                return max_flow

            self.iter = [0]*self.v_count
            flow = self.dfs(source, sink, self.inf)

            while flow > 0:
                max_flow += flow
                flow = self.dfs(source, sink, self.inf)

    def bfs(self, source: int):
        level, edges = [-1]*self.v_count, self.edges
        level[source] = 0
        dq = deque([source])
        popleft, append = dq.popleft, dq.append

        while dq:
            v = popleft()
            for dest, cap, _rev in edges[v]:
                if cap > 0 > level[dest]:
                    level[dest] = level[v] + 1
                    append(dest)

        self.level = level

    def dfs(self, source: int, sink: int, flow: int) -> int:
        if source == sink:
            return flow
        while self.iter[source] < len(self.edges[source]):
            dest, cap, rev = edge = self.edges[source][self.iter[source]]
            if cap > 0 and self.level[source] < self.level[dest]:
                flowed = self.dfs(dest, sink, flow if flow < cap else cap)
                if flowed > 0:
                    edge[1] -= flowed
                    self.edges[dest][rev][1] += flowed
                    return flowed
            self.iter[source] += 1

        return 0


if __name__ == "__main__":
    import sys
    N, G, E = map(int, input().split())
    edges = [[N+1, 0, 100]]
    append = edges.append
    for p in (map(int, input().split())):
        append([p, N, 1])
    for a, b in (map(int, l.split()) for l in sys.stdin):
        append([a, b, 1])
        append([b, a, 1])

    dinic = Dinic(N+2, edges)
    print(dinic.solve(N+1, N))