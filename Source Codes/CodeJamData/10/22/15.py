#!/usr/bin/python

import sys

C = int(sys.stdin.readline())
for c in xrange(C):
    N, K, B, T = [int(x) for x in sys.stdin.readline().split()]
    X = [int(x) for x in sys.stdin.readline().split()]
    V = [int(x) for x in sys.stdin.readline().split()]
    if K == 0:
        print "Case #%d: 0" % (c+1)
        continue

    good = []
    for i in xrange(N):
        if V[i]* T >= B-X[i]:
            good.append(i)
    if len(good) < K:
        print "Case #%d: IMPOSSIBLE" % (c+1)
        continue
    good = good[len(good)-K:]
    G = 0
    for g in xrange(1, len(good)):
        G += g*(good[g] - good[g-1] - 1)
    G += (N - good[-1] - 1) * len(good)
    print "Case #%d: %d" % (c+1, G)

