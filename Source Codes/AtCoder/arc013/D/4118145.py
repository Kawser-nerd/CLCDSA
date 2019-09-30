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
        self.level[s] = 0
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


N = int(input())
M = 20**3

dinic = Dinic(2 + M*2)
nodes = set()

def add_xyz(x, y, z):
    for j in range(1,x):
        s0 = j*y*z
        s1 = (x-j)*y*z
        dinic.add_edge(2+s0-1, 2+M+s1-1, 1)
        nodes.add(s0)

for i in range(N):
    x,y,z = map(int, input().split())

    add_xyz(x,y,z)
    add_xyz(y,z,x)
    add_xyz(z,x,y)

for n in nodes:
    dinic.add_edge(0, 2+n-1, 1)
    dinic.add_edge(2+M+n-1, 1, 1)

f = dinic.max_flow(0, 1)

print((len(nodes) - f)*2 + f)