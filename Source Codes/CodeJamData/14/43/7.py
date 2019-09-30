#!/usr/bin/python

from sys import stdin

def line():
	return map( int, stdin.readline().strip().split() )

def sline():
	return stdin.readline().strip().split()

T, = line()

for T in xrange(1,T+1):
	W, H, B = line()
	M = [ '.' * W for i in xrange(H) ]
	for i in xrange(B):
		x1, y1, x2, y2 = line()
		for y in xrange(y1,y2+1):
			M[y] = M[y][:x1]+(x2-x1+1)*'#'+M[y][x2+1:]

	M = [ list(m) for m in M ]

	A = 0

	for i in xrange(W):
		Q = [ (i,0, 0) ]
		DIR = [ (0,1), (-1,0), (0,-1), (1,0) ]
		while len(Q) > 0:
			x, y, D = Q.pop()
			if x < 0 or y < 0 or x >= W or y >= H or M[y][x] != '.':
				continue

			M[y][x] = str(A)[0]

			if y == H-1:
				A += 1
				break

			for d in [ (D+3)%4, D, (D+1)%4 ]:
				Q.append( (x+DIR[d][0], y+DIR[d][1], d) )

	print 'Case #%d: %d' % (T, A)

	#M = [ ''.join(m) for m in M ]
	#M.reverse()
	#print '\n'.join(M)
