#!/usr/bin/python

import sys

NCASE = int(sys.stdin.readline())

for case in range(1,NCASE+1):
	n = int(sys.stdin.readline())
        a = map(int, sys.stdin.readline().split())
        y = sum( max(a[i-1]-a[i],0) for i in xrange(1,n) )
        mx = max( max(a[i-1]-a[i],0) for i in xrange(1,n) )
        z = sum( min(mx,a[i-1]) for i in xrange(1,n) )

	print 'Case #%d: %d %d' % (case, y, z)
