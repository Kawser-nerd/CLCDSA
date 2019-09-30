#!/usr/bin/python

from __future__ import division
import sys

# map(int, sys.stdin.readline().split())

ncases = int(sys.stdin.readline())
for case in xrange(ncases):
    (p, k, l) = map(int, sys.stdin.readline().split())
    freq = map(int, sys.stdin.readline().split())
    freq.sort()
    freq.reverse()

    r = 0
    for i in xrange(len(freq)):
        r += freq[i] * (i//k + 1)

    print "Case #%d: %d" % (case+1, r)

