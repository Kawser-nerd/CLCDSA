import collections
class Dinic:
    def __init__(self, n):
        self.n = n
        self.g = [[] for i in range(n)]
    def add_edge(self, fr, to, cap):
        self.g[fr].append([to, cap, len(self.g[to])])
        self.g[to].append([fr, 0, len(self.g[fr])-1])
    def add_multi_edge(self, v1, v2, cap1, cap2):
        self.g[v1].append([v2, cap1, len(self.g[v2])])
        self.g[v2].append([v1, cap2, len(self.g[v1])-1])
    def bfs(self, s):
        level = [-1]*self.n
        deq = collections.deque()
        level[s] = 0
        deq.append(s)
        while deq:
            v = deq.popleft()
            for e in self.g[v]:
                if e[1]>0 and level[e[0]]<0:
                    level[e[0]] = level[v] + 1
                    deq.append(e[0])
        self.level = level
    def dfs(self, v, t, f):
        if v==t: return f
        es = self.g[v]
        level = self.level
        for i in range(self.it[v], len(self.g[v])):
            e = es[i]
            if e[1]>0 and level[v]<level[e[0]]:
                d = self.dfs(e[0], t, min(f, e[1]))
                if d>0:
                    e[1] -= d
                    self.g[e[0]][e[2]][1] += d
                    self.it[v] = i
                    return d
        self.it[v] = len(self.g[v])
        return 0
    def max_flow(self, s, t):
        flow = 0
        while True:
            self.bfs(s)
            if self.level[t]<0: break
            self.it = [0]*self.n
            while True:
                f = self.dfs(s, t, 10**9+7)
                if f>0:
                    flow += f
                else:
                    break
        return flow

N = int(input())
B = 8000
dinic = Dinic(B*2+2)
idx = 0
used = set()
def add(X, Y, Z):
    global idx
    P = Y*Z
    for x in range(1, X):
        used.add(x*P)
        dinic.add_edge(2+x*P-1, 2+B+(X-x)*P-1, 1)
for i in range(N):
    X, Y, Z = map(int, input().split())
    add(X, Y, Z)
    add(Y, Z, X)
    add(Z, X, Y)
for x in used:
    dinic.add_edge(0, 2+x-1, 1)
    dinic.add_edge(2+B+x-1, 1, 1)
f = dinic.max_flow(0, 1)
print((len(used)-f)*2 + f)