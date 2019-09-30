#!/usr/bin/env python

import sys

line = sys.stdin.readline()
line = line.rstrip()

cases = int(line)

for case in xrange(0, cases):
    K = int(sys.stdin.readline().strip())
    ds = map(int, sys.stdin.readline().rstrip().split())
    ds[0:1] = []

    indexes = range(0,K)
    cards = [-1]*K

    I = 0
    for X in xrange(0,K):
        I+=X
        I = I%(len(indexes))
        ii = I%(K-X)
        i = indexes[ii]
        indexes[ii:ii+1] = []
        cards[i] = X

    sys.stdout.write("Case #%d:" % (case+1))
    for d in ds:
        sys.stdout.write(" %d" % (cards[d-1]+1))
    sys.stdout.write("\n")

