import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools

sys.setrecursionlimit(10**7)
inf = 10**20
gosa = 1.0 / 10**10
mod = 10**9 + 7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()


def main():
    n,k = LI()
    e = collections.defaultdict(list)
    t = []
    for _ in range(n-1):
        a,b = LI_()
        e[a].append(b)
        e[b].append(a)
        t.append((a,b))

    r = inf
    q = [0] * n
    k2 = k//2
    if k%2 == 0:
        for i in range(n):
            v = [-1] * n
            v[i] = 0
            q[0] = i
            qi = qe = 0
            while qi <= qe:
                c = q[qi]
                for ni in e[c]:
                    if v[ni] >= 0:
                        continue
                    if v[c] == k2:
                        continue
                    v[ni] = v[c] + 1
                    qe += 1
                    q[qe] = ni
                qi += 1
            tr = n-qe-1
            if r > tr:
                r = tr
    else:
        for i in range(n-1):
            a,b = t[i]
            v = [-1] * n
            v[a] = v[b] = 0
            q[0] = a
            q[1] = b
            qi = 0
            qe = 1
            while qi <= qe:
                c = q[qi]
                for ni in e[c]:
                    if v[ni] >= 0:
                        continue
                    v[ni] = v[c] + 1
                    if v[ni] > k2:
                        continue
                    qe += 1
                    q[qe] = ni
                qi += 1
            tr = n-qe-1
            if r > tr:
                r = tr

    return r

print(main())