#!/usr/bin/env python2.5

import sys
infile = open(sys.argv[1], 'rb')
numcases = int(infile.readline())

def gettime(s):
	t = s.split(":")
	return int(t[0])*60 + int(t[1])
	
for case in xrange(1, numcases+1):
	turnaround = int(infile.readline())
	counts = [int(x) for x in infile.readline().split()]
	a = [infile.readline().strip().split() for x in xrange(counts[0])]
	a = [[gettime(l[0]), gettime(l[1])] for l in a]
	a.sort()
	b = [infile.readline().strip().split() for x in xrange(counts[1])]
	b = [[gettime(l[0]), gettime(l[1])] for l in b]
	b.sort()
	fa = []
	fb = []
	ac = 0
	bc = 0
	while len(a) > 0 and len(b) > 0:
		if a[0][0] < b[0][0]:
			if len(fa) > 0 and fa[0] <= a[0][0]:
				fa=fa[1:]
			else:
				ac += 1
			fb.append(a[0][1] + turnaround)
			fb.sort()
			a = a[1:]
		else:
			if len(fb) > 0 and fb[0] <= b[0][0]:
				fb=fb[1:]
			else:
				bc += 1
			fa.append(b[0][1] + turnaround)
			fa.sort()
			b = b[1:]
	
	while len(a) > 0:
		if len(fa) > 0 and fa[0] <= a[0][0]:
			fa=fa[1:]
		else:
			ac+=1
		a=a[1:]
			
	while len(b) > 0:
		if len(fb) > 0 and fb[0] <= b[0][0]:
			fb=fb[1:]
		else:
			bc+=1
		b=b[1:]
	
	print "Case #" + str(case) + ": " + str(ac) + " " + str(bc)
	
	