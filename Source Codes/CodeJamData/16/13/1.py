#! /usr/bin/env python

import sys
fin = open(sys.argv[1], "r")
fout = open("p3.out", "w")

T = int(fin.readline())
for tt in xrange(T):
    N = int(fin.readline())
    out = map(int, fin.readline().split())
    out = map(lambda x: x-1, out)

    ans = 0

    best = [0 for j in xrange(N)]
    for i in xrange(N):
        cur = i
        vis = [0 for j in xrange(N)]
        vis[cur] = 1
        while vis[out[cur]] == 0:
            vis[out[cur]] = 1
            cur = out[cur]
        if out[cur] == i:
            ans = max(ans, sum(vis))

        if out[out[cur]] == cur:
            best[cur] = max(best[cur], sum(vis))

    tot = 0
    for i in xrange(N):
        if out[out[i]] == i:
            tot += best[i] + best[out[i]] - 2

    tot /= 2
    ans = max(ans, tot)

    fout.write("Case #" + str(tt+1) + ": " + str(ans) + "\n")
