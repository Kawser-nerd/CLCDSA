import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools

sys.setrecursionlimit(10**7)
inf = 10**20
mod = 10**9 + 7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()


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
            if s1 < s2:
                self.table[s1] += self.table[s2]
                self.table[s2] = s1
            else:
                self.table[s2] += self.table[s1]
                self.table[s1] = s2
            return True
        return False

    def subsetall(self):
        d = collections.defaultdict(set)
        for i in range(len(self.table)):
            t = self.find(i)
            d[t].add(i)
        return d.items()

def main():
    n = I()
    s1 = [c for c in S()]
    s2 = [c for c in S()]
    uf = UnionFind(36)
    d = collections.defaultdict(int)
    for i in range(n):
        c1 = int(s1[i], 36)
        c2 = int(s2[i], 36)
        if d[c1] == 0:
            d[c1] = i+1
        if d[c2] == 0:
            d[c2] = i+1
        uf.union(c1, c2)

    r = 1
    for k,s in uf.subsetall():
        t = min([d[c] for c in s])
        if k < 10:
            continue
        if t == 0:
            continue
        if t == 1:
            r *= 9
        else:
            r *= 10

    return r


print(main())