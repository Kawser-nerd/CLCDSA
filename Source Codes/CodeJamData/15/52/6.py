#!/usr/bin/python

import math, collections, itertools
import sys

NCASE = int(sys.stdin.readline())


for case in range(1,NCASE+1):
    N,K = map(int, sys.stdin.readline().split())
    SUM = map(int, sys.stdin.readline().split())

    A = [0] * N
    mxd, mnd = [0]*K, [0]*K
    for i in xrange(0, len(SUM)-1):
        d = SUM[i+1]-SUM[i]     # A[i+K]-A[i]
        A[i+K] = A[i] + d
        k = i % K
        mxd[k] = max(A[i+K], mxd[k])
        mnd[k] = min(A[i+K], mnd[k])

#    print >> sys.stderr, A
#    print >> sys.stderr, mxd, mnd

    mxrng = max( mxd[i]-mnd[i] for i in xrange(K) )
    r = next( i for i in xrange(K) if mxd[i]-mnd[i]==mxrng )
    
    smn = sum( mnd[r]-d for d in mnd )
    smx = sum( mxd[r]-d for d in mxd )

    if (SUM[0]-smn) % K <= smx-smn:
        ans = mxrng
    else:
        ans = mxrng + 1

    print 'Case #%d: %d' % (case, ans)

