#!/usr/bin/python

from sys import stdin

from random import randint

def line():
	return map( int, stdin.readline().strip().split() )



N = 1000

def good():
	A = range(N)
	for k in xrange(N):
		p = randint(k,N-1)
		A[k], A[p] = A[p], A[k]
	return A

def bad():
	A = range(N)
	for k in xrange(N):
		p = randint(0,N-1)
		A[k], A[p] = A[p], A[k]
	return A

T, = line()
for j in xrange(1, T+1):
	#z = randint(0,1)
	#A = [good,bad][z]()
	N, = line()
	A = line()
	rate = 0
	for i, a in enumerate(A[:-1]):
		if a <= i:
			a += i
		rate += (a-i) ** 0.25

	rate /= 1e4
	y = rate > 0.396
	#right = (z==0) == y

	print 'Case #%d: %s' % (j, 'GOOD' if y else 'BAD')



