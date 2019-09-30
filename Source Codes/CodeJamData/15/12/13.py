#!/usr/bin/python

import sys

NCASE = int(sys.stdin.readline())

def bsStartTime(A, k):
    mn, mx = min(A), max(A)
    kk = max(k-len(A), 0)
    bg, ed = 0, mx*(kk+1)
    while ed-bg > 1:
        md = (bg+ed) / 2
        c = sum( (md+a-1)/a for a in A )
        if c >= k: ed = md
        else: bg = md
    return bg

for case in range(1,NCASE+1):
	N, K = map(int, sys.stdin.readline().split())
        A = map(int, sys.stdin.readline().split())

        start = bsStartTime(A, K)
        m = K - sum( (start-1+a-1)/a for a in A ) - sum( 1 for a in A if (start-1)%a==0 )
        for (i,a) in enumerate(A):
            if start%a == 0:
                m -= 1
                if m == 0: 
                    break

	print 'Case #%d: %d' % (case, i+1)

