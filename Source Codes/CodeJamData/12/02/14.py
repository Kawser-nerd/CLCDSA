#!/usr/bin/python

import sys, re, string, math, fractions, itertools
from fractions import Fraction

ssr = sys.stdin.readline
ssw = sys.stdout.write
def rdline(): return ssr().strip()
def rdstrs(): return ssr.split()
def rdints(): return map(int, ssr().split())



def do_one_case(cnum):
    v = rdints()
    (N, S, p) = v[:3]
    t = v[3:]
    assert len(t)==N

    nums = 0
    numns = 0
    for x in t:
        mn = max(0, x/3 - 1)
        mx = min(10, (x+2)/3 + 1)
        r = range(mn, mx+1)
        tplx = [ (s1, s2, s3) for s1 in r for s2 in r for s3 in r if s1+s2+s3==x ]
        tpls = [ tt for tt in tplx if max(tt) - min(tt) <= 2 ]
        tplns = [ tt for tt in tpls if max(tt) - min(tt) < 2 ]
        maxs = max([-99] + [ max(tt) for tt in tpls])
        maxns = max([-99] + [ max(tt) for tt in tplns])
        if maxs>=p: nums += 1
        if maxns>=p: numns += 1
    nn = min(nums, numns+S)
    print "Case #%d: %d" % (cnum, nn)


def main():
    N = int(rdline())
    for i in range(N):
        do_one_case(i+1)


if __name__ == "__main__":
    main()
