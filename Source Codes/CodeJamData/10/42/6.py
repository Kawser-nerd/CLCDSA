#!/usr/bin/python

import sys
f = open(sys.argv[1])
casenum = int(f.readline())

for casei in xrange(casenum):
	res = 0
	P = int(f.readline())	
	_ = f.readline().splitlines()[0].split()
	M = [P - int(x) for x in _]

	costs = []
	attending = []
	#for p in reversed(xrange(0,P)):
	for p in xrange(0,P):
		_ = f.readline().splitlines()[0].split()
		costs.append([int(x) for x in _])
	#print M,costs
	#print M
	for p in reversed(xrange(1,P+1)):
		curoff = 0
		#print 'p = %d' % p
		for x in xrange(((1 << P)/(1 << p))):
			#print 'aaaaaaaaaaa'
			needstobuy = False
			for _ in xrange(curoff,curoff+(1 << p)):
				#print _
				if M[_] > 0:
					needstobuy = True
					#print _,'aaa'
			if needstobuy:
				res += 1
				for _ in xrange(curoff,curoff+((1 << p))):
					M[_] -= 1
			curoff += (1 << p)
	#print M
	print 'Case #%d: %d' % (casei+1,res)
				
		
		
		
	
