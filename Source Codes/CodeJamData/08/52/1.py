#!/usr/bin/python

fin = open("b.in", "r")
fout = open("b.out", "w")

INF = 100000000

def carray(dims, init):
	if dims:
		return map(lambda x: carray(dims[1:], init), range(dims[0]))
	else:
		return init

cache = {}
def portals(grid, q):
	if q in cache:
		return cache[q]
	ports = []
	y = q[0]
	while grid[y][q[1]]:
		y += 1
	ports.append((y-1, q[1]))
	y = q[0]
	while grid[y][q[1]]:
		y -= 1
	ports.append((y+1, q[1]))
	
	x = q[1]
	while grid[q[0]][x]:
		x += 1
	ports.append((q[0], x-1))
	x = q[1]
	while grid[q[0]][x]:
		x -= 1
	ports.append((q[0], x+1))
	
	cache[q] = ports
	return ports
	
n = int(fin.readline())
for i in xrange(1, n+1):
	cache = {}
	r, c = map(int, fin.readline().split())
	
	grid = map(lambda x: [False]*(c+2), range(r+2))
	
	start = None
	end = None
	cw = carray([r+2, c+2], 0)
	
	
	for j in xrange(r):
		for k, ch in enumerate(fin.readline().strip()):
			if ch == '.' or ch == 'O' or ch == 'X':
				grid[j+1][k+1] = True
				cw[j+1][k+1] = INF
			
			if ch == 'O':
				start = (j+1, k+1)
			if ch == 'X':
				end = (j+1, k+1)
	
	r += 2
	c += 2
	#print start
	#print end
	#for line in grid:
#		print line
	
	best = carray([r, c], INF)
	
	Q = []
	for y in range(r):
		for x in range(c):
			if not grid[y][x]:
				Q.append((y, x))
	
	
	while Q:
		p = Q[0]
		py, px = p
		s = cw[py][px]
		del Q[0]
		for q in [(py+1, px), (py, px+1), (py-1, px), (py, px-1)]:
			(y, x) = q
			if y < r and x < c and y >= 0 and x >= 0 and cw[y][x] > s + 1:
				cw[y][x] = s + 1
				Q.append(q)
		
		
	#print cw
	Q = [(start, 0)]
	best[start[0]][start[1]] = 0
	
	while Q:
		p, v = Q[0]
		del Q[0]
		
		s = cw[p[0]][p[1]]
		
		for q in [(p[0]+1, p[1]), (p[0], p[1]+1), (p[0]-1, p[1]), (p[0], p[1]-1)]:
			y, x = q
			if grid[y][x]:
				if best[y][x] > v + 1:
					best[y][x] = v + 1
					Q.append((q, v+1))
					#todo: append portals
			
		for q in portals(grid, p):
			y, x = q
			if best[y][x] > v + s:
				best[y][x] = v + s
				Q.append((q, v+s))
				
	#for line in best:
	#	print line
	
	result = best[end[0]][end[1]]
	print i, result
	if result >= INF:
		print >> fout, "Case #%d: THE CAKE IS A LIE" % (i)
	else:
		print >> fout, "Case #%d: %d" % (i, result)

