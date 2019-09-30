#!/usr/bin/python

import sys

def calcGCD(a, b):
	while b > 0:
		a, b = b, a%b
	return a

C = int(sys.stdin.readline())

for i in range(1,C+1):
	s = sys.stdin.readline().split()
	N = int(s[0])
	x = []
	for j in range(1, N+1):
		x.append(int(s[j]))
	x.sort()
	d = []
	for j in range(1, N):
		if x[j] != x[j-1]:
			d.append(x[j]-x[j-1])
	gcd = d[0]
	for j in range(1, len(d)):
		gcd = calcGCD(gcd, d[j])
	y = (gcd - (x[0]%gcd)) % gcd
	print 'Case #%d: %d' % (i, y)

