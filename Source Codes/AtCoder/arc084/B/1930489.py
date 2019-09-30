import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools

sys.setrecursionlimit(10**7)
inf = 10**20
eps = 1.0 / 10**15
mod = 10**9+7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()
def pf(s): return print(s, flush=True)


def main():
    K = I()

    # ???????
    def search(s):
        d = collections.defaultdict(lambda: inf)
        q = [(1,s)]
        d[s] = 1
        qi = 0
        v = [False] * (K+1)
        v[s] = True
        while len(q):
            k, u = heapq.heappop(q)
            if u == 0:
                return k
            t = u*10 % K
            v[u] = True
            while not v[t]:
                if t == 0:
                    return k
                if d[t] > k:
                    heapq.heappush(q, (k, t))
                    d[t] = k
                v[t] = True
                t = t*10 % K

            i = 1
            t = (u+i) % K
            while not v[t] and t != u:
                if d[t] > k+1:
                    heapq.heappush(q, (k+1, t))
                    d[t] = k+1
                    i = i*10 % K
                    t = (u+i) % K
                else:
                    break

    return search(1)

print(main())