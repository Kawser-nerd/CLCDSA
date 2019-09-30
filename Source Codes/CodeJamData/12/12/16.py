#!/usr/bin/python

import sys, re, string, math, fractions, itertools
from fractions import Fraction

ssr = sys.stdin.readline
ssw = sys.stdout.write
def rdline(): return ssr().strip()
def rdstrs(): return ssr.split()
def rdints(): return map(int, ssr().split())



def do_one_case(cnum):
    (N,) = rdints()
    abi = []
    for i in range(N):
        (a,b) = rdints()
        abi.append((a,b,i))
    d = N*[0]
    s = 0
    n = 0
    while s<2*N:
        (b, i) = min([(b,i) for (a,b,i) in abi if d[i]<2])
        if b<=s:
            s += 2-d[i]
            d[i] = 2
            n += 1
            continue
        bai = [(b,a,i) for (a,b,i) in abi if d[i]==0 and a<=s]
        if not bai:
            print "Case #%d: Too Bad" %(cnum,)
            return
        (b, a, i) = max(bai)
        s += 1
        d[i] = 1
        n += 1
    print "Case #%d: %d" % (cnum, n)




def main():
    N = int(rdline())
    for i in range(N):
        do_one_case(i+1)


if __name__ == "__main__":
    main()
