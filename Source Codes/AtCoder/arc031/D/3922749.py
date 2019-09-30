# seishin.py
from collections import deque
class Dinic:
    def __init__(self, N):
        self.N = N
        self.G = [[] for i in range(N)]

    def add_edge(self, fr, to, cap):
        forward = [to, cap, None]
        forward[2] = backward = [fr, 0, forward]
        self.G[fr].append(forward)
        self.G[to].append(backward)

    def add_multi_edge(self, v1, v2, cap1, cap2):
        edge1 = [v2, cap1, None]
        edge1[2] = edge2 = [v1, cap2, edge1]
        self.G[v1].append(edge1)
        self.G[v2].append(edge2)

    def bfs(self, s, t):
        self.level = level = [None]*self.N
        deq = deque([s])
        level[s] = 0
        G = self.G
        while deq:
            v = deq.popleft()
            lv = level[v] + 1
            for w, cap, _ in G[v]:
                if cap and level[w] is None:
                    level[w] = lv
                    deq.append(w)
        return level[t] is not None

    def dfs(self, v, t, f):
        if v == t:
            return f
        level = self.level
        for e in self.it[v]:
            w, cap, rev = e
            if cap and level[v] < level[w]:
                d = self.dfs(w, t, min(f, cap))
                if d:
                    e[1] -= d
                    rev[1] += d
                    return d
        return 0

    def flow(self, s, t):
        flow = 0
        INF = 10**9 + 7
        G = self.G
        while self.bfs(s, t):
            *self.it, = map(iter, self.G)
            f = INF
            while f:
                f = self.dfs(s, t, INF)
                flow += f
        return flow


N, M = map(int, input().split())
*S, = map(int, input().split())
*T, = map(int, input().split())
R = []
for i in range(N):
    k, *A = map(int, input().split())
    R.append(A)
SS = sum(S)

def solve(x):
    dinic = Dinic(2+N+M)
    for i in range(N):
        dinic.add_edge(0, i+2, S[i])
    for i in range(M):
        dinic.add_edge(2+N+i, 1, T[i]*x)
    for i in range(N):
        for j in R[i]:
            dinic.add_edge(i+2, 2+N+j-1, 100)
    return dinic.flow(0, 1) >= SS

EPS = 1e-5
left = 0; right = 10**4
while right - left > EPS:
    mid = (left + right) / 2
    if solve(mid):
        right = mid
    else:
        left = mid
print(left)