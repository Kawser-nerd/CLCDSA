from collections import deque

N,G,E = map(int,input().split())
gs = list(map(int,input().split()))
es = [[] for i in range(N+1)] # [[to1,cap1,rev1], ...]

def add_edge(fr,to,cap):
    es[fr].append([to,cap,len(es[to])])
    es[to].append([fr,cap,len(es[fr])-1])

for i in range(E):
    a,b = map(int,input().split())
    add_edge(a,b,1)
for g in gs:
    add_edge(g,N,1)

INF = float('inf')
level = [0] * (N+1)
iters = [0] * (N+1)

def dinic_max_flow(s,t):
    global iters

    def _bfs(s):
        global level
        level = [-1] * (N+1)
        level[s] = 0
        q = deque([s])
        while q:
            v = q.popleft()
            for to,cap,rev in es[v]:
                if cap > 0 and level[to] < 0:
                    level[to] = level[v] + 1
                    q.append(to)

    def _dfs(v,t,f):
        if v == t: return f
        for i in range(iters[v],len(es[v])):
            iters[v] += 1
            to,cap,rev = es[v][i]
            if es[v][i][1] > 0 and level[v] < level[to]:
                d = _dfs(to,t,min(f,es[v][i][1]))
                if d > 0:
                    es[v][i][1] -= d #cap
                    es[to][rev][1] += d
                    return d
        return 0

    flow = 0
    while True:
        _bfs(s)
        if level[t] < 0: return flow
        iters = [0] * (N+1)
        f = 0
        while True:
            f = _dfs(s,t,INF)
            if f <= 0: break
            flow += f

print(dinic_max_flow(0,N))