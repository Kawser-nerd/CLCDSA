#!/usr/bin/env python

import sys

def do_trial(f):
    N = int(f.readline())
    xN = [int(x) for x in f.readline().split()]
    yN = [int(x) for x in f.readline().split()]
    xN.sort()
    yN.sort()
    yN.reverse()
    t = sum(xN[n] * yN[n] for n in range(N))
    return t

f = sys.stdin
T = int(f.readline())
for i in xrange(T):
    v = do_trial(f)
    print "Case #%d: %d" % (i+1, v)
