#!/usr/bin/python

def CC(a,b):
	if b > a or b < 0:
		return 0
	assert b < 4
	result = 1
	for k in xrange(b):
		result *= (a-k)
	for k in xrange(b):
		result /= (k+1)
	return result

N = int(raw_input())

for i in xrange(N):
	n, A, B, C, D, x0, y0, M = [int(s) for s in raw_input().split()]

	mat = [[0,0,0],[0,0,0],[0,0,0]]
	x0 = x0 % M
	y0 = y0 % M
	for j in xrange(n):
		mat[x0%3][y0%3] += 1
		x0 = (A * x0 + B) % M
		y0 = (C * y0 + D) % M

	result = 0
	for p1 in xrange(9):
		for p2 in xrange(p1,9):
			for p3 in xrange(p2,9):
				p1x = p1 % 3
				p1y = p1 / 3
				p2x = p2 % 3
				p2y = p2 / 3
				p3x = p3 % 3
				p3y = p3 / 3
				if (p1x+p2x+p3x) % 3 or (p1y+p2y+p3y) % 3:
					continue
				pmat = [[0,0,0],[0,0,0],[0,0,0]]
				pmat[p1x][p1y] += 1
				pmat[p2x][p2y] += 1
				pmat[p3x][p3y] += 1
				inc = 1
				for px in xrange(3):
					for py in xrange(3):
						inc *= CC(mat[px][py],pmat[px][py])
				result += inc
	print "Case #%d: %d" % (i+1,result)
