#!/usr/bin/python

from sys import stdin, stderr

def line():
	return map( int, stdin.readline().strip().split() )

T, = line()

for T in xrange(1,T+1):
	N, = line()
	V = [ [] for i in xrange(N) ]

	for i in xrange(N-1):
		a,b = line()
		V[a-1].append(b-1)
		V[b-1].append(a-1)

	best = 1
	for root in xrange(N):
		Q = [root]
		P = range(N)
		P[root] = None

		for v in Q:
			for u in V[v]:
				if u != P[v]:
					Q.append(u)
					P[u] = v

		Q.reverse()
		A = [ [] for i in xrange(N) ]

		for v in Q:
			val = 1
			if len(A[v]) >= 2:
				A[v].sort()
				val = sum(A[v][-2:])+1

			if P[v] != None:
				A[P[v]].append(val)
			else:
				if val > best:
					best = val

	print 'Case #%d: %d' % (T, N-best)
	print >>stderr, 'Case #%d: %d' % (T, N-best)





