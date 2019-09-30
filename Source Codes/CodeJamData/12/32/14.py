#!/usr/bin/env python
# -*- coding: utf-8 -*-

def rt(f):
	ws = ' \t\n'
	while True:
		c = f.read(1)
		if c not in ws: break
	l = [c]
	while True:
		c = f.read(1)
		if c in ws: break
		l.append(c)
	return ''.join(l)

def ri(f): return int(rt(f))
def rf(f): return float(rt(f))


def compute(d,t,a):
	return max(t, (2.0*d/a)**0.5) 

def compute2(d,a):
	return (2.0*d/a)**0.5

from sys import stdin
t = ri(stdin)
for testcase in xrange(1, t+1):
	D,N,A = rf(stdin), ri(stdin), ri(stdin)
	
	if N==1:
		t0, x0 = rf(stdin), rf(stdin)
	
		print "Case #%d:"%testcase	
		for _ in xrange(A):
			print compute2(D,rf(stdin))	
	else:
	
		t0, x0, t1, x1 = rf(stdin), rf(stdin), rf(stdin), rf(stdin)
	
		s = D - x0
		v = (x1-x0)/t1
		td = s/v

		print "Case #%d:"%testcase	
		for _ in xrange(A):
			print compute(D,td, rf(stdin))

	
