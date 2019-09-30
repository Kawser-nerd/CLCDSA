#!/usr/bin/python

import sys, re, string, math, fractions, itertools
from fractions import Fraction

ssr = sys.stdin.readline
ssw = sys.stdout.write
def rdline(): return ssr().strip()
def rdstrs(): return ssr.split()
def rdints(): return map(int, ssr().split())



def do_one_case(cnum):
    (A, B) = rdints()
    p = map(float, ssr().split())
    assert len(p)==A
    m = B+2
    pp = 1.0
    for i in range(A):
        k = A-i-1
        pp *= p[i]
        x = 2*k + B - A + 1 + (1-pp)*(B+1)
        m = min(m, x)
    print "Case #%d: %.8f" % (cnum, m)


def main():
    N = int(rdline())
    for i in range(N):
        do_one_case(i+1)


if __name__ == "__main__":
    main()
