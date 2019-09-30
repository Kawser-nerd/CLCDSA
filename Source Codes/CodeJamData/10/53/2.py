#!/usr/bin/python

import sys
f = open(sys.argv[1])
casenum = int(f.readline())

for casei in xrange(casenum):
	res = 0
	C = int(f.readline())
	corners = {}
	for z in xrange(C):
		_ = f.readline().splitlines()[0].split()
		x,n = (int(x) for x in _)
		corners[x] = n
	while corners.values().count(1) != len(corners):
		needmoves = [k for k, v in corners.iteritems() if v > 1]
		for x in needmoves:
			n = corners[x]
			if n == 2:
				del corners[x]
			else:
				corners[x] = n - 2
			corners[x-1] = corners.get(x-1,0) + 1
			corners[x+1] = corners.get(x+1,0) + 1
			res += 1
			
	
	
		
	print 'Case #%d: %s' % (casei+1,res)
