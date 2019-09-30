#! /usr/bin/python

import sys

def gcd(a, b):
	if b == 0:
		return a
	return gcd(b, a%b)

def readVI():
	vs = sys.stdin.readline().split(' ')
	vi = [int(s) for s in vs]
	return vi[1:]

C = int(sys.stdin.readline())
for t in xrange(1, C+1):
	vi = readVI()
	minv = min(vi)
	vim = [i-minv for i in vi]
	agcd = 0
	for i in vim:
		agcd = gcd(i, agcd)
	if agcd > 0:
		minv = minv%agcd
	else:
		minv = 0

	if minv > 0:
		print "Case #%d: %d" % (t, agcd-minv)
	else:
		print "Case #%d: 0" % t

