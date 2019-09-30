# -*- coding: utf-8 -*-
n = int(input())
ax = []
ay = []
for i in range(n):
    x,y = map(int, input().split())
    ax.append((x,i))
    ay.append((y,i))

ax.sort()
ay.sort()

edge = []
for i in range(n-1):
    v = ax[i][1]
    u = ax[i+1][1]
    c = abs(ax[i][0]-ax[i+1][0])
    edge.append((c,v,u))

    v = ay[i][1]
    u = ay[i+1][1]
    c = abs(ay[i][0]-ay[i+1][0])
    edge.append((c,v,u))

edge.sort()



class UnionFind():
    def __init__(self, n):
        self.par = [i for i in range(n)]
    def find(self, x):
        if self.par[x] == x:
            return x
        else:
            self.par[x] = self.find(self.par[x])
            return self.par[x]
    def unite(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if x==y:
            return

        if x<y:
            self.par[y] = x
        else:
            self.par[x] = y
    def same(self, x, y):
        return self.find(x) == self.find(y)

t = UnionFind(n)
res = 0
for e in edge:
    cost = e[0]
    v = e[1]
    u = e[2]

    if not t.same(v,u):
        # print((v,u,cost))
        t.unite(v,u)
        res += cost

print(res)