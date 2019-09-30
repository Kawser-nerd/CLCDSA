#!/usr/bin/python2
from math import *

_42 = int(raw_input())

def calc(A, B, prob):
	ans = 1000000000000000000.
	p = 1.
	for i in xrange(A+1):
		ans = min(ans, (A-i) + (B-i) + 1 + (1-p)*(B+1))
		p *= prob[i]
	return ans

for _ in xrange(_42):
	[A,B] = [int(x) for x in raw_input().split(' ')]
	prob = [float(x) for x in raw_input().split(' ')]
	prob.append(1)
	ans = min(float(B+2), calc(A, B, prob))
	print "Case #%d: %.6f" % (_ + 1, ans)
