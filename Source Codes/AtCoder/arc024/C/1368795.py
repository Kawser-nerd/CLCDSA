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

def main():
    n,k = LI()
    s = [ord(c) - 97 for c in S()]
    ts = [0] * 26
    d = collections.defaultdict(int)
    for i in range(k-1):
        ts[s[i]] += 1
    for i in range(n-k+1):
        if i > 0:
            ts[s[i-1]] -= 1
        ts[s[i+k-1]] +=1
        t = tuple(ts)
        if d[t] == 0:
            d[t] = i+1
        elif d[t] + k <= i+1:
            return 'YES'
    return 'NO'

print(main())