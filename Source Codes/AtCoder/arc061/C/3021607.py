import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools

sys.setrecursionlimit(10**7)
inf = 10**20
eps = 1.0 / 10**10
mod = 10**9+7
dd = [(-1,0),(0,1),(1,0),(0,-1)]
ddn = [(-1,0),(-1,1),(0,1),(1,1),(1,0),(1,-1),(0,-1),(-1,-1)]

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()
def pf(s): return print(s, flush=True)


class UnionFind:
    def __init__(self, size):
        self.table = [-1 for _ in range(size)]

    def find(self, x):
        if self.table[x] < 0:
            return x
        else:
            self.table[x] = self.find(self.table[x])
            return self.table[x]

    def union(self, x, y):
        s1 = self.find(x)
        s2 = self.find(y)
        if s1 != s2:
            if self.table[s1] <= self.table[s2]:
                self.table[s1] += self.table[s2]
                self.table[s2] = s1
            else:
                self.table[s2] += self.table[s1]
                self.table[s1] = s2
            return True
        return False

    def subsetall(self):
        a = []
        for i in range(len(self.table)):
            if self.table[i] < 0:
                a.append((i, -self.table[i]))
        return a

    def tall(self):
        d = collections.defaultdict(list)
        for i in range(len(self.table)):
            d[self.find(i)].append(i)
        return d

def main():
    M = 2**17
    n,m = LI()
    a = [LI() for _ in range(m)]
    e = collections.defaultdict(list)
    for p,q,c in a:
        pc = p+c*M
        qc = q+c*M
        pm = p-M
        qm = q-M
        e[pc].append(qc)
        e[qc].append(pc)
        e[pm].append(pc)
        e[qm].append(qc)
        e[pc].append(pm)
        e[qc].append(qm)

    def search():
        d = collections.defaultdict(lambda: inf)
        s = 1-M
        d[s] = 0
        q = []
        heapq.heappush(q, (0, s))
        v = set()
        while len(q):
            k, u = heapq.heappop(q)
            if u in v:
                continue
            v.add(u)
            if u < 0:
                for uv in e[u]:
                    if uv in v:
                        continue
                    vd = k + 1
                    if d[uv] > vd:
                        d[uv] = vd
                        heapq.heappush(q, (vd, uv))

            else:
                if u % M == n:
                    return k

                for uv in e[u]:
                    if uv in v:
                        continue
                    if d[uv] > k:
                        d[uv] = k
                        heapq.heappush(q, (k, uv))

        return -1

    return search()



print(main())