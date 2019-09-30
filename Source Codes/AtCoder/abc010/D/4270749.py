import collections


class FordFulkerson:
    """
    Verified with http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
    """

    def __init__(self):
        self.g = collections.defaultdict(lambda: collections.defaultdict(int))

    def add_edge(self, u, v, c):
        self.g[u][v] = c

    def dfs(self, u, t, f, used: set):
        """
        :param u: visiting node
        :param t: sink
        :param f: flow
        :param used: node u is used?
        :return: min(c, f)
        """
        if u == t:
            return f

        used.add(u)

        # visit next node
        for v, c in self.g[u].items():
            if v not in used and c > 0:
                f = min(c, f)
                d = self.dfs(v, t, f, used)

                # update the graph if a path is found
                if d > 0:
                    self.g[u][v] -= d
                    self.g[v][u] += d
                    return d

        # path is not found
        return 0

    def max_flow(self, s, t):
        """Calculate maximum flow from s to t on the network

        :param s: source
        :param t: sink
        :return: max flow on the network
        """
        f = 0
        while True:
            d = self.dfs(s, t, float("inf"), set())
            if d == 0:  # nothing to update any more
                break
            f += d
        return f


def solve():
    N, G, E = map(int, input().split())
    girls = map(int, input().split())

    SINK = -1
    solver = FordFulkerson()
    for p in girls:
        solver.add_edge(p, SINK, 1)

    for _ in range(E):
        u, v = map(int, input().split())
        solver.add_edge(u, v, 1)
        solver.add_edge(v, u, 1)

    ans = solver.max_flow(0, SINK)
    print(ans)


if __name__ == '__main__':
    solve()