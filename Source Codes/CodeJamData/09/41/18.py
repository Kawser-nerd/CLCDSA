#!/usr/bin/python

import sys

def solve(a):
	res = 0
	for t in xrange(1,len(a)):
		if a[t-1] <= t:
			continue
		for i in xrange(t,len(a)):
			if a[i] <= t:
				res += i-t+1
				saved = a[i]
				for j in xrange(i,t-1,-1):
					a[j] = a[j-1]
				a[t-1] = saved
				break
	return res


nCases = int(sys.stdin.readline())
for c in xrange(1,nCases+1):
	n = int(sys.stdin.readline())
	a = []
	for i in xrange(n):
		s = sys.stdin.readline().strip()
		m = 0
		for j,x in enumerate(s):
			if x == '1':
				m = j+1
		a.append(m)
	print "Case #"+str(c)+": " + str(solve(a))
