#!/usr/bin/python

import collections
import sys

CBG, CED = 0, 100
if len(sys.argv) > 1:
    CBG, CED = map(int, sys.argv[1:])

NCASE = int(sys.stdin.readline())

for case in range(1,NCASE+1):
    N = int(sys.stdin.readline())
    SB = [ sys.stdin.readline().split() for _ in xrange(N) ]
    if case < CBG or case > CED: continue
    S = SB[2:]

    LB = collections.defaultdict(int)
    for w in SB[0]:
        LB[w] |= 1
    for w in SB[1]:
        LB[w] |= 2

    mn = 100000
    for b in xrange(1<<(N-2)):
        L = dict(LB)
        for i in xrange(N-2):
            m = 1 if (b&(1<<i)) > 0 else 2
            for w in S[i]:
                L[w] = L.get(w,0) | m
        cnt = sum( 1 for (k,v) in L.iteritems() if v==3 )
        mn = min(mn, cnt)

    print 'Case #%d: %d' % (case, mn)

