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
 
def main():
    N = I()
    a = []
    b = []
    for i in range(N):
        x,y = LI()
        a.append((x,i))
        b.append((y,i))
    a.sort()
    b.sort()
    t = []
    for i in range(1,N):
        t.append((a[i][0]-a[i-1][0], a[i][1], a[i-1][1]))
        t.append((b[i][0]-b[i-1][0], b[i][1], b[i-1][1]))
    t.sort()
    r = 0
    uf = UnionFind(N)
    for c,d,e in t:
        if uf.union(d,e):
            r += c
 
    return r
 
print(main())