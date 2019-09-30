#!/usr/bin/python

from sys import stdin, stderr

def line():
	return map( int, stdin.readline().strip().split() )

def sline():
	return stdin.readline().strip().split()

T, = line()

for T in xrange(1,T+1):
	P, Q, N = line()

	HG = [ line() for i in xrange(N) ]
	best = [ None, 0 ]

	for H, G in HG:
		tower_can = (H-1)/Q

		best2 = [ None for i in best ] + [None] * (tower_can+1) 
		for i in xrange(len(best)):
			best2[i+tower_can+1] = best[i]

		hp_left = H-Q*tower_can
		i_need = (hp_left-1)/P+1
		mod_need = tower_can-i_need

		for i in xrange(len(best)):
			if i+mod_need >= 0 and best[i] != None:
				best2[i+mod_need] = max(best2[i+mod_need], best[i]+G)
		best = best2


	print >>stderr, 'Case #%d' % T
	print 'Case #%d: %d' % (T, max(best))
