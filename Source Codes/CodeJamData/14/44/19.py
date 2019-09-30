#!/usr/bin/python

from sys import stdin

def line():
	return map( int, stdin.readline().strip().split() )

def sline():
	return stdin.readline().strip().split()

T, = line()

for T in xrange(1,T+1):
	M, N = line()
	S = [ sline()[0] for i in xrange(M) ]
	X = [ [] ]

	for m in xrange(M):
		Y = []
		for x in X:
			for n in xrange(N):
				Y.append(x+[n])
		X = Y

	X = [ x for x in X if len(set(x)) == N ]

	bestA, nA = 0, 0

	for x in X:
		V = {}
		for n in xrange(N):
			for si, nn in enumerate(x):
				if n == nn:
					s = S[si]
					for i in xrange(len(s)+1):
						prev_v, prev_n = V.get(s[:i], (0, -1) )
						if prev_n != n:
							V[s[:i]] = (prev_v+1, n)

		A = 0
		for k, (v, n) in V.items():
			A += v

		if A > bestA:
			bestA, nA = A, 0

		if A == bestA:
			nA += 1

	print 'Case #%d: %d %d' % (T, bestA, nA%1000000007)
