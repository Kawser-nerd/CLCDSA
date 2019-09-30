class UnionFind:
    def __init__(self, n):
        #?????????????par[x] == x?????????root
        self.par = [i for i in range(n)]
        #???????????0?
        self.rank = [0] * n

    def find(self, x):
        #???????
        if self.par[x] == x:
            return x
        else:
            self.par[x] = self.find(self.par[x])
            return self.par[x]

    def same(self, x, y):
        # x?y?????????????
        return self.find(x) == self.find(y)

    def union(self, x, y):
        #????
        #??????
        x = self.find(x)
        y = self.find(y)
        if self.rank[x] < self.rank[y]:
            self.par[x] = y
        else:
            self.par[y] = x
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1

n, m = map(int, input().split())
edge = [list(map(int, input().split())) for i in range(m)]

def C(x):
    #??x??????????
    #ci - ti * x?????????????????
    #sum (ci - ti * x) <= 0?????????????
    u = UnionFind(n)
    edge.sort(key = lambda y:y[2] - y[3] * x)
    s = 0
    for i in range(m):
        ai, bi, ci, ti = edge[i]
        if (ci - ti * x) < 0:
            s += ci - ti * x
            u.union(ai, bi)
        elif (not (u.same(ai, bi)) and (s + ci - ti * x <= 0)):
            s += ci - ti * x
            u.union(ai, bi)
    for i in range(n-1):
        if not u.same(i, i+1):
            return False
    return True

lb = 0.0
ub = 1000000.0
while (ub - lb > 0.001):
    mid = (lb + ub) / 2
    if (C(mid)):
        ub = mid
    else:
        lb = mid
print(ub)