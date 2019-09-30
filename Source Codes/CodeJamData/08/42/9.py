#!/usr/bin/python

from __future__ import division

import sys

def solve(a, n, m):
    for x1 in xrange(0, n+1):
        for x2 in xrange(0, n+1):
            for y1 in xrange(0, m+1):
                #for y2 in xrange(0, m+1):
                    x1y2 = a + y1*x2
                    if x1 == 0:
                        if x1y2 == 0:
                            return (x1, y1, x2, 1)
                        continue
                    if x1y2 % x1 != 0:
                        continue
                    y2 = x1y2 / x1
                    if 0 <= y2 <= m:
                        return (x1, y1, x2, y2)
    return None

cases = int(sys.stdin.readline())
for case in xrange(1, cases+1):
    n, m, a = [int(x) for x in sys.stdin.readline().split()]

    res = solve(a, n, m)

    print "Case #%d:" % case,
    if res is None:
        print "IMPOSSIBLE"
    else:
        print "0 0 %d %d %d %d" % res
