import os, sys

T = int(raw_input())
for TK in xrange(T):
	R, C = map(int, raw_input().split(' '))
	grid = []
	for i in xrange(R):
		grid.append(raw_input())
		grid[-1] = list(grid[-1])
	for i in xrange(R):
		for j in xrange(C):
			if grid[i][j] != '?':
				for k in xrange(1, C):
					if j-k >= 0 and grid[i][j-k] == '?':
						grid[i][j-k] = grid[i][j]
					else:
						break
				for k in xrange(1, C):
					if j+k < C and grid[i][j+k] == '?':
						grid[i][j+k] = grid[i][j]
					else:
						break
	for i in xrange(R):
		if i > 0 and all([x == '?' for x in grid[i]]):
			grid[i] = grid[i-1]
	for i in xrange(R-2, -1, -1):
		if all([x == '?' for x in grid[i]]):
			grid[i] = grid[i+1]
	print 'Case #%d:' % (TK+1)
	for i in xrange(R):
		print ''.join(grid[i])
