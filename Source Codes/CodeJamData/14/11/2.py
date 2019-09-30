#!/usr/bin/python

from sys import stdin

def line():
	return map( int, stdin.readline().strip().split() )

def sline():
	return stdin.readline().strip().split()

T, = line()

for T in xrange(1,T+1):
	N, L = line()
	
	A = [ int(a,2) for a in sline() ]
	B = [ int(b,2) for b in sline() ]

	C = None
	for a in A:
		D = set( a^b for b in B)
		
		if C == None:
			C = D
		else:
			C = C.intersection(D)

	if len(C) == 0:
		print 'Case #%d: NOT POSSIBLE' % T
	else:
		C = [ bin(c)[2:] for c in C ]
		C = [ c.replace('0','') for c in C ]
		C = [ len(c) for c in C ]
		print 'Case #%d: %d' % (T, min(C))
