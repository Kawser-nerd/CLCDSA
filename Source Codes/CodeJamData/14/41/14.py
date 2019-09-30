#!/usr/bin/python

import sys, re, string, math, fractions, itertools
from fractions import Fraction
from bisect import bisect_right

ssr = sys.stdin.readline
ssw = sys.stdout.write
def rdline(): return ssr().strip()
def rdstrs(): return ssr().split()
def rdints(): return map(int, ssr().split())
def rd1int(): return int(rdline())



def do_one_case(cnum):
    N, X = rdints()
    S = rdints()
    N2 = N//2
    N1 = 2*N2
    assert len(S)==N
    S.sort()
    m = 0
    while S:
        m += 1
        a = S.pop()
        if S and S[0]+a <= X:
            i = bisect_right(S, X-a)
            if i>0:
                assert a+S[i-1] <= X
                del S[i-1]

    print "Case #%d: %d" % (cnum, m)


def main():
    N = rd1int()
    for i in range(N):
        do_one_case(i+1)


if __name__ == "__main__":
    main()
