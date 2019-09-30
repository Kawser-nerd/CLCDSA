#!/usr/bin/env python

import math

fin = open("1.in", "r")
fout = open("1.out", "w")

T = int(fin.readline())
for t in range(T):
    print str(t+1)
    N, K = map(int, fin.readline().split())

    P = [] # list of pancakes
    for i in range(N):
        r, h = map(int, fin.readline().split())
        P.append((r, h, 2 * h * r))
    P.sort() # sort by radius in increasing order
    print P
    ans = 0
    for j in range(N-1, K-2, -1): # max radius is P[j][0]
        max_radius = P[j][0]
        area = P[j][2] + max_radius * max_radius
        del P[j]
        filtered = [hr for (r, h, hr) in P if r <= max_radius]
        filtered.sort()
        print filtered
        for i in range(1, K):
            area += filtered[-i]
        ans = max(ans, area)

    ans *= math.pi
    ans = '{0:.6f}'.format(ans)
    fout.write("Case #" + str(t+1) + ": " + ans + "\n")
