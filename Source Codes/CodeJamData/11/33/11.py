#!/usr/bin/python

import sys
from itertools import islice

def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

def lcm(a, b):
    return a*b/gcd(a,b)

def main():
    T = int(next(sys.stdin))
    for test in xrange(1, T+1):
        N, L, H = map(int, next(sys.stdin).split())
        notes = map(int, next(sys.stdin).split())
        l = reduce(gcd, notes)
        h = reduce(lcm, notes)
        print l, h, L, H
        if l >= L and l <= H:
            print "Case #%s: %s" % (test, l)
        elif h >= L and h <= H:
            print "Case #%s: %s" % (test, h)
        else:
            print "Case #%s: %s" % (test, 'NO')

main()
