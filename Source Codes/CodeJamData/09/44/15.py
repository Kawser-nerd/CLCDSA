#!/usr/bin/python

import sys
from math import sqrt

class Obj:
	pass

def dist(o1,o2):
    return (sqrt((o1.x-o2.x)**2+(o1.y-o2.y)**2)+o2.r+o1.r)/2.0

def solve(a):
	n = len(a)
	if n == 1:
		return a[0].r
	if n == 2:
		return max(a[0].r, a[1].r)
	res = max(dist(a[0],a[1]),a[2].r)
	res = min(res,max(dist(a[0],a[2]),a[1].r))
	res = min(res,max(dist(a[1],a[2]),a[0].r))
	return res

nCases = int(sys.stdin.readline())
for c in xrange(1,nCases+1):
	n = int(sys.stdin.readline())
	a = []
	for i in xrange(n):
		o = Obj();
		(o.x, o.y, o.r) = [int(x) for x in sys.stdin.readline().split()]
		a.append(o)
	print "Case #" + str(c) + ": " + repr(solve(a))
