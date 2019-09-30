from collections import defaultdict

class UF():
    def __init__(self,n):
        self.l = [-1]*n
    def root(self, a):
        if self.l[a] < 0:
            return a
        else:
            self.l[a] = self.root(self.l[a])
        return self.l[a]
    def unite(self, a, b):
        a, b = self.root(a), self.root(b)
        if a == b:
            return
        if self.l[a] > self.l[b]:
            a, b = b, a
        self.l[a] += self.l[b]
        self.l[b] = a

n,k,l = map(int, input().split())
d = UF(n)
t = UF(n)
for i in range(k):
    r,s = map(int,input().split())
    d.unite(r-1, s-1)
for i in range(l):
    r,s = map(int,input().split())
    t.unite(r-1, s-1)
d_set = defaultdict(set)
t_set = defaultdict(set)
for i in range(n):
    d_set[d.root(i)].add(i)
    t_set[t.root(i)].add(i)

ans = []
cache = {}
for i in range(n):
    rd = d.root(i)
    rt = t.root(i)
    if (rd,rt) in cache:
        ans.append(cache[(rd,rt)])
    else:
        _ = len(d_set[rd] & t_set[rt])
        cache[(rd,rt)] = _
        ans.append(_)
print(*ans)