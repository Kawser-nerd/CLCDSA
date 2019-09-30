#!/usr/bin/python

from sys import stdin

def line():
	return map( int, stdin.readline().strip().split() )

def sline():
	return stdin.readline().strip().split()

T, = line()

for T in xrange(1,T+1):
	N, = line()
	S = line()

	A = 0
	while len(S) > 0:
		best = 0
		for i, v in enumerate(S):
			if v < S[best]:
				best = i

		A += min(best, len(S)-best-1)
		S = S[:best]+S[best+1:]

	print 'Case #%d: %d' % (T, A)
