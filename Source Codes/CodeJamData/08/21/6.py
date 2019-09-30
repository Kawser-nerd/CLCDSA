#!/usr/bin/env python2.5
import math, sys, os, re

# we're looking for x1, x2, x3 s.t. x1+x2+x3 is a multiple of 3.
# Separate trees into 9 equivalence classes.

DEBUG = False
def getline(file, types):
    parts = file.readline().strip().split()
    got = []
    for i in xrange(len(parts)):
        got.append(types[i](parts[i]))
    return got

def run_file(file, out=None):
    if out is None and isinstance(file, basestring) and file.endswith('.in'):
        out = file[:-3]+'.out'
    if out is None: outfile = sys.stdout
    else: outfile = open(out, 'w')
    if isinstance(file, basestring): file = open(file)

    ncases = getline(file, (int,))[0]
    for case in xrange(ncases):
        n, A, B, C, D, x0, y0, M = getline(file, (int, int, int, int, int, int,
        int, int))
        answer = run_case(n, A, B, C, D, x0, y0, M)
        print >> outfile, "Case #%d: %d" % (case+1, answer)

def run_case(n, A, B, C, D, x0, y0, M):
    buckets = [[0, 0, 0] for i in range(3)]
    X = x0
    Y = y0
    for i in xrange(n):
        buckets[X%3][Y%3] += 1
        X = (A * X + B) % M
        Y = (C * Y + D) % M
    total = 0
    for x1 in range(3):
        for y1 in range(3):
            for x2 in range(3):
                for y2 in range(3):
                    x3 = (6-x1-x2)%3
                    y3 = (6-y1-y2)%3
                    b1 = buckets[x1][y1]
                    b2 = buckets[x2][y2]
                    b3 = buckets[x3][y3]
                    if (x2, y2) == (x1, y1): b2 = max(0, b2-1)
                    if (x3, y3) == (x1, y1): b3 = max(0, b3-1)
                    if (x3, y3) == (x2, y2): b3 = max(0, b3-1)
                    if DEBUG and b1*b2*b3 > 0:
                        print (x1, y1), (x2, y2), (x3, y3), b1, b2, b3
                    total += b1*b2*b3
    assert total % 6 == 0
    return total/6

if __name__ == '__main__':
    import sys
    if len(sys.argv) > 1: run_file(sys.argv[1])
    else: run_file(sys.stdin)

