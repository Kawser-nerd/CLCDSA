from collections import deque


class Dinic:
    def __init__(self, n):
        self.n = n
        self.links = [[] for _ in range(n)]
        self.depth = None
        self.progress = None

    def add_link(self, _from, to, cap):
        self.links[_from].append([cap, to, len(self.links[to])])
        self.links[to].append([0, _from, len(self.links[_from]) - 1])

    def bfs(self, s):
        depth = [-1] * self.n
        depth[s] = 0
        q = deque([s])
        while q:
            v = q.popleft()
            for cap, to, rev in self.links[v]:
                if cap > 0 and depth[to] < 0:
                    depth[to] = depth[v] + 1
                    q.append(to)
        self.depth = depth

    def dfs(self, v, t, flow):
        if v == t:
            return flow
        for i, link in enumerate(self.links[v]):
            if i < self.progress[v]:
                continue
            self.progress[v] = i
            cap, to, rev = link
            if cap == 0 or self.depth[v] >= self.depth[to]:
                continue
            d = self.dfs(to, t, min(flow, cap))
            if d == 0:
                continue
            link[0] -= d
            self.links[to][rev][0] += d
            return d
        return 0

    def max_flow(self, s, t):
        flow = 0
        while True:
            self.bfs(s)
            if self.depth[t] < 0:
                return flow
            self.progress = [0] * self.n
            current_flow = self.dfs(s, t, float('inf'))
            while current_flow > 0:
                flow += current_flow
                current_flow = self.dfs(s, t, float('inf'))


n = int(input())
an = list(map(int, input().split()))
mf = Dinic(n + 2)
max_value = 0
for i, a in enumerate(an):
    i += 1
    if a > 0:
        max_value += a
        mf.add_link(i, n + 1, a)
    else:
        mf.add_link(0, i, -a)
    for j in range(2 * i, n + 1, i):
        mf.add_link(i, j, float('inf'))
print(max_value - mf.max_flow(0, n + 1))