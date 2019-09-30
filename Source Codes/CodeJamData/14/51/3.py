#!/usr/bin/python

from sys import stdin, stderr

def line():
	return map( int, stdin.readline().strip().split() )

def sline():
	return stdin.readline().strip().split()

T, = line()

for T in xrange(1,T+1):
	N, p, q, r, s = line()
	A = [ (i*p+q) % r + s for i in xrange(N) ]

	total = sum(A)
	totalsum = [ a for a in A ]
	for i in xrange(1,N):
		totalsum[i] += totalsum[i-1]

	def getsum(a,b):
		kA = totalsum[a-1] if a > 0 else 0
		kB = totalsum[b] - kA
		kC = total - totalsum[b]
		return max(kA, kB, kC)

	best = total
	if False:
		for a in xrange(N):
			for b in xrange(a,N):
				best = min( best, max( sum(A[:a]), sum(A[a:b+1]), sum(A[b+1:]) ) )

	b = 0
	for a in xrange(N):
		if b < a:
			b += 1
		while b < N-1 and getsum(a,b) >= getsum(a,b+1):
			b += 1

		best = min( best, getsum(a,b) )

	best = total - best

	print >>stderr, 'Case #%d' % T
	print 'Case #%d: %.10f' % (T, 1.0*best/total)
