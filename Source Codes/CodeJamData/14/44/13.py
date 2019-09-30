#!/usr/bin/python

import sys, re, string, math, fractions, itertools
from fractions import Fraction

ssr = sys.stdin.readline
ssw = sys.stdout.write
def rdline(): return ssr().strip()
def rdstrs(): return ssr().split()
def rdints(): return map(int, ssr().split())
def rd1int(): return int(rdline())

MOD = 10**9 + 7
upper = [ chr(65+i) for i in range(26) ]
cm = [ (i+2)*[None] for i in range(101) ]


def solve(s):
    #print s, [s+x for x in upper if s+x in P ]
    if s in D:
        #print "foo!"
        return D[s]
    l = [ solve(s+x) for x in upper if s+x in P ]
    if s in S:
        l.append((1,1,0))
    #print s, l
    l1 = [ i for (i,j,k) in l ]
    l2 = [ j for (i,j,k) in l ]
    l3 = [ k for (i,j,k) in l ]
    mx = max(l1)
    a = min(N, sum(l1))
    c = sum(l3) + a
    b = 0
    for i in range(mx, a+1):
        b1 = modprod(cm[i][j] for j in l1) 
        b2 = (cm[a][i] * b1) % MOD
        #print "a=%d i=%d b2=%d" % (a, i,b2)
        b += (-1 if (a-i)&1 else 1) * b2
    b %= MOD
    b = (b + MOD) % MOD
    #print "b0 =", b
    b *= modprod(l2)
    b %= MOD
    #print s, "->", (a,b,c)
    D[s] = (a,b,c)
    return (a,b,c)


def mp2(x,y):
    return (x*y) % MOD

def modprod(g):
    return reduce(mp2, g)

def do_one_case(cnum):
    global N, S, P, D
    M, N = rdints()
    S = set(rdline() for i in range(M))
    P = set(x[:i] for x in S for i in range(len(x)+1))
    D = {}
    (n, w, m) = solve("")
    w *= cm[N][n]
    w %= MOD
    print "Case #%d: %d %d" % (cnum, m, w)
    

def initcm():
    for i in range(101):
        cm[i][0] = 1
        cm[i][i+1] = 0
        for j in range(i):
            cm[i][j+1] = (cm[i-1][j] + cm[i-1][j+1]) % MOD


def main():
    initcm()
    T = rd1int()
    for i in range(T):
        do_one_case(i+1)


if __name__ == "__main__":
    main()
