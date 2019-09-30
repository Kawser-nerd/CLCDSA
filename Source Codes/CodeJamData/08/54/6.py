#!/usr/bin/python

fin = open("d.in", "r")
fout = open("d.out", "w")

def carray(dims, init):
	if dims:
		return map(lambda x: carray(dims[1:], init), range(dims[0]))
	else:
		return init

S = 105
cc = carray([S+2, S+2], 0)
cc[0][0] = 1

for i in xrange(S):
	for j in xrange(S):
		cc[i+1][j+2] += cc[i][j]
		cc[i+2][j+1] += cc[i][j]
		

def comb(x, y):
	return cc[x][y]
	if x > 2*y or y > x*x:
		return 0
	elif x == 2*y or y == w*x:
		return 1
	else:
		return 10
	
def calc(start, end, rocks):
	M = 10007
	if rocks:
		return (calc(start, end, rocks[1:]) - calc(rocks[0], end, rocks[1:]) * calc(start, rocks[0], [])) % M
	else:
		xd = end[1] - start[1]
		yd = end[0] - start[0]
		return comb(xd, yd) % M
	
n = int(fin.readline())
for i in xrange(1, n+1):
	h, w, r = map(int, fin.readline().split())
	rocks = []
	for j in xrange(r):
		rocks.append(map(int, fin.readline().split()))
	rocks.sort()
	result = calc((1,1), (h, w), rocks)
	print result
	print >> fout, "Case #%d: %d" % (i, result)

