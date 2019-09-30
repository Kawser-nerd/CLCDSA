class Ford_Fulkerson:
    def __init__(self, N):
        self.used = [False] * (N + 1)
        self.G = [[0] * (N + 1) for i in range(N + 1)]

    def add_edge(self, fr, to, cap):
        self.G[fr][to] = cap
        # self.G[to][fr] = cap

    def dfs(self, v, t, f):
        if v == t:
            return f

        self.used[v] = True
        for i in range(N + 1):
            if v == i:
                continue
            if (not self.used[i]) and self.G[v][i] > 0:
                d = self.dfs(i, t, min(f, self.G[v][i]))
                if d > 0:
                    self.G[v][i] -= d
                    self.G[i][v] += d
                    return d
        return 0

    def max_flow(self):
        flow = 0
        while True:
            F.used = [False] * (N + 1)
            f = F.dfs(0, N, 10 ** 9)
            if f == 0:
                break
            flow += f

        return flow


N, G, E = map(int, input().split())
p = list(map(int, input().split()))
F = Ford_Fulkerson(N)
for i in range(G):
    F.add_edge(p[i], N, 1)

for i in range(E):
    a, b = map(int, input().split())
    F.add_edge(a, b, 1)
    F.add_edge(b, a, 1)

print(F.max_flow())