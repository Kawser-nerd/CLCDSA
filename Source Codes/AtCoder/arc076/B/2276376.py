n = int(input())
xs = []
ys = []

for i in range(n):
    x, y = map(int, input().split())
    xs.append((x, i))
    ys.append((y, i))


xs.sort()
ys.sort()

es = []

for i in range(n-1):
    es.append((xs[i+1][0] - xs[i][0], xs[i][1], xs[i+1][1]))
    es.append((ys[i+1][0] - ys[i][0], ys[i][1], ys[i+1][1]))

es.sort()

class UF:
    def __init__(self):
        self.p = {}
    def find(self, x):
        if x not in self.p:
            self.p[x] = x
        if x == self.p[x]:
            return x
        self.p[x] = self.find(self.p[x])
        return self.p[x]
    def merge(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if x != y:
            self.p[x] = y


uf = UF()
ans = 0
try:
    for d, i0, i1 in es:
        c0 = uf.find(i0)
        c1 = uf.find(i1)
        if c0 == c1:
            continue
        ans += d
        uf.merge(i0, i1)
    print(ans)
except:
    print(0)