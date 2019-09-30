import collections
class Dinic:
    def __init__(self, vnum):
        self.edge = [[] for i in range(vnum)]
        self.n = vnum
        self.inf = float('inf')
    def addedge(self, st, en, c):
        self.edge[st].append([en, c, len(self.edge[en])])
        self.edge[en].append([st, 0, len(self.edge[st])-1])
    def bfs(self, vst):
        dist = [-1]*self.n
        dist[vst] = 0
        Q = collections.deque([vst])
        while Q:
            nv = Q.popleft()
            for vt, c, r in self.edge[nv]:
                if dist[vt] == -1 and c > 0:
                    dist[vt] = dist[nv] + 1
                    Q.append(vt)
        self.dist = dist
    def dfs(self, nv, en, nf):
        nextv = self.nextv
        if nv == en:
            return nf
        dist = self.dist
        ist = nextv[nv]
        for i, (vt, c, r) in enumerate(self.edge[nv][ist:], ist):
            if dist[nv] < dist[vt] and c > 0:
                df = self.dfs(vt, en, min(nf, c))
                if df > 0:
                    self.edge[nv][i][1] -= df
                    self.edge[vt][r][1] += df
                    return df
            nextv[nv] += 1
        return 0
    def getmf(self, st, en):
        mf = 0
        while True:
            self.bfs(st)
            if self.dist[en] == -1:
                break
            self.nextv = [0]*self.n
            while True:
                fl = self.dfs(st, en, self.inf)
                if fl > 0:
                    mf += fl
                else:
                    break
        return mf

def inpl(): return [int(i) for i in input().split()]
N = int(input())
a = inpl()
K = Dinic(N+2)
inf = float('inf')
for i, v in enumerate(a,1):
    if v > 0:
        K.addedge(i, N+1, v)
    else:
        K.addedge(0, i, -v)
for i in range(1,N+1):
    for j in range(2*i, N+1, i):
        K.addedge(i, j, inf)

print(sum([i for i in a if i > 0]) - K.getmf(0, N+1))