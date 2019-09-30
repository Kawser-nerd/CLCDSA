#!/usr/bin/env python

import sys

filename=sys.argv[1]
inputfile=file(filename, 'r')
numcases=int(inputfile.readline().strip())
for case in range(1,numcases+1):
    N, M, A = map(long, inputfile.readline().strip().split())
    doublearea = 0
    for x2 in xrange(N+1):
	for y2 in xrange(M+1):
	    for x3 in xrange(x2, N+1):
		for negy3 in xrange(M-y2+1):
		    y3=-negy3
		    doublearea = x3*y2 - y3*x2
		    if doublearea >= A: break
		if doublearea == A: break
	    if doublearea == A: break
	if doublearea == A: break
    if doublearea == A:
	print "Case #%d: %d %d %d %d %d %d" % (case, 0, -y3, x2, y2-y3, x3, 0)
    else:
	print "Case #%d: IMPOSSIBLE" % case
