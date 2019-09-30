#!/usr/bin/env python

import sys

line = sys.stdin.readline()
line = line.rstrip()

cases = int(line)

for case in xrange(0, cases):
    (n, A, B, C, D, x0, y0, M) = map(int, sys.stdin.readline().rstrip().split())

    buckets = [[0,0,0] for y in xrange(0,3)]

    X = x0
    Y = y0
    for i in xrange(0, n):
        buckets[X%3][Y%3]+=1
        X = (A*X+B)%M
        Y = (C*Y+D)%M

    count = 0

    for x in xrange(0, 3):
        for y in xrange(0, 3):
            n = buckets[x][y]
            count += n*(n-1)*(n-2)/6

    for i in xrange(0, 3):
        count += buckets[i][0]*buckets[i][1]*buckets[i][2]
        count += buckets[0][i]*buckets[1][i]*buckets[2][i]

    for i in xrange(0, 3):
        count += buckets[0][i]*buckets[1][(i+1)%3]*buckets[2][(i+2)%3]
        count += buckets[0][i]*buckets[1][(i-1)%3]*buckets[2][(i-2)%3]

    print "Case #%d: %d" % (case+1, count)
