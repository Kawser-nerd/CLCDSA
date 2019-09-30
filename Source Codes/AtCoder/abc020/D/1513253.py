import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools

sys.setrecursionlimit(10**7)
inf = 10**20
gosa = 1.0 / 10**9
mod = 10**9 + 7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()

def divisions(n):
    sq = int(math.sqrt(n)+1)
    d = collections.defaultdict(int)
    while n % 2 == 0:
        n //= 2
        d[2] += 1
    i = 3
    while n > 1 and sq >= i:
        if n % i == 0:
            n //= i
            d[i] += 1
        else:
            i += 2

    if n > 1:
        d[n] += 1

    r = [1]
    for k, v in d.items():
        for c in r[:]:
            for i in range(1,v+1):
                r.append(c*(k**i))

    return sorted(r)

def main():
    n,k = LI()
    r = 0

    dl = divisions(k)[::-1]
    dr = collections.defaultdict(int)
    for di in range(len(dl)):
        d = dl[di]
        t = n//d
        wa = (d * (t+1)) * t // 2
        for dj in range(di):
            j = dl[dj]
            if j % d == 0:
                wa -= dr[j]
        dr[d] = wa % mod
        r += wa * k // fractions.gcd(k,d) % mod
        r %= mod

    return r



print(main())