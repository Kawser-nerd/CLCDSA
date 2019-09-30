import queue

class Dinic:
    def __init__(self, v, inf = 1000000007):
        self.V = v
        self.inf = inf
        self.G = [[] for _ in range(v)]
        self.level = [0 for _ in range(v)]
        self.iter = [0 for _ in range(v)]

    def add_edge(self, from_, to, cap):
        # to: ???, cap: ??, rev: ?????
        self.G[from_].append({'to':to, 'cap':cap, 'rev':len(self.G[to])})
        self.G[to].append({'to':from_, 'cap':0, 'rev':len(self.G[from_])-1})

    # s????????bfs???
    def bfs(self, s):
        self.level = [-1 for _ in range(self.V)]
        self.level[s] = 0;
        que = queue.Queue()
        que.put(s)
        while not que.empty():
            v = que.get()
            for i in range(len(self.G[v])):
                e = self.G[v][i]
                if e['cap'] > 0 and self.level[e['to']] < 0:
                    self.level[e['to']] = self.level[v] + 1
                    que.put(e['to'])

    # ?????dfs???
    def dfs(self, v, t, f):
        if v == t: return f
        for i in range(self.iter[v], len(self.G[v])):
            self.iter[v] = i
            e = self.G[v][i]
            if e['cap'] > 0 and self.level[v] < self.level[e['to']]:
                d = self.dfs(e['to'], t, min(f, e['cap']))
                if d > 0:
                    e['cap'] -= d
                    self.G[e['to']][e['rev']]['cap'] += d
                    return d

        return 0

    def max_flow(self, s, t):
        flow = 0
        while True:
            self.bfs(s)
            # bfs?????
            if self.level[t] < 0 : return flow
            self.iter = [0 for _ in range(self.V)]
            f = self.dfs(s, t, self.inf)
            while f > 0:
                flow += f
                f = self.dfs(s,t, self.inf)
 
 
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
    return dinic.max_flow(0, 1) >= SS
 
EPS = 1e-5
left = 0;
right = 10**4
while (EPS < (right - left)):
    mid = (left + right) / 2
    if solve(mid):
        right = mid
    else:
        left = mid
print(left)