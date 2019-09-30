#!/usr/bin/python

import sys
from itertools import islice

def solve(L, t, N, C, a):
    tot_dist = 0
    eff_dists = []
    for s in xrange(N):
        d = a[s % len(a)]
        if tot_dist + d <= t:
            eff_dists.append((d, 0))
        else:
            if tot_dist >= t:
                eff_dists.append((d, d))
            else:
                eff_dists.append((d, d - (t - tot_dist)))
        tot_dist += d

#    print eff_dists

    tot_time = 0
    for dist, eff_dist in sorted(eff_dists, key=lambda x: x[1], reverse=True):
        if L > 0:
#            print '-1'
            tot_time += eff_dist + 2 * (dist - eff_dist)
            L -= 1
        else:
#            print '-2'
            tot_time += dist * 2
#        print dist, eff_dist, L, tot_time

    return tot_time // 2

def main():
    T = int(next(sys.stdin))
    for test in xrange(1, T+1):
        print >>sys.stderr, test
        line = next(sys.stdin)
        L, t, N, C, a = line.split(None, 4)
        L, t, N, C = map(int, (L, t, N, C))
        a = list(int(ai)*2 for ai in a.split())
        print "Case #%s: %s" % (test, solve(L, t, N, C, a))

main()
