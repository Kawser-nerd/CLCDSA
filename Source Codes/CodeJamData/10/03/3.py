#!/usr/bin/env python

import sys
import math

T = int(sys.stdin.readline())
for i in xrange(T):
    R, k, N = [int(x) for x in sys.stdin.readline().split()]
    l = [int(x) for x in sys.stdin.readline().split()]
    n = []
    for j in xrange(N):
        t = (j+1) % N
        s = l[j]
        ss = 1
        while (t != j):
            if (s + l[t] > k): break
            s += l[t]
            ss += 1
            t = (t+1) % N
        n.append([s, ss])
    s = 0
    cur = 0
    las = [-1]*N
    ss = [0]
    j = 0
    while j < R:
        if las[cur] != -1: break
        las[cur] = j
        s += n[cur][0]
        ss.append(s)
        cur = (cur+n[cur][1]) % N
        j += 1

    period = j - las[cur]
    points = s - ss[las[cur]]
    s = ss[las[cur]] + points * ((R-las[cur]) / period) + ss[las[cur]+((R-las[cur])%period)] - ss[las[cur]]
    print "Case #" + str(i+1) + ": " + str(s)
