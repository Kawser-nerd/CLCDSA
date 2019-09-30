#! /usr/bin/env python

import sys
import heapq
import itertools
fin = open(sys.argv[1], "r")
fout = open("p2.out", "w")

T = int(fin.readline())
for tt in xrange(T):
    print tt+1

    P, Q, N = map(int, fin.readline().split())
    
    h, g = [0 for i in xrange(N)], [0 for i in xrange(N)]
    for i in xrange(N):
        h[i], g[i] = map(int, fin.readline().split())

    print h, g

    left = [[-1 for i in xrange(1011)] for j in xrange(N+1)]
    left[0][0] = 0
    left[0][1] = 0

    for i in xrange(1, N+1):
        hits = (h[i-1] - 1) / Q + 1
        need = (h[i-1] - (hits - 1) * Q - 1) / P + 1
        for j in xrange(10 * N):
            left[i][j] = left[i-1][max(j - hits, 0)]
            if j + need >= hits - 1 and left[i-1][j + need - hits + 1] != -1:
                left[i][j] = max(left[i][j], left[i-1][j + need - hits + 1] + g[i-1])

    ans = max(left[N])
    fout.write("Case #" + str(tt+1) + ": " + str(ans) + "\n")
