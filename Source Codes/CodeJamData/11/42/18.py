#!/usr/bin/python

name = 'B-small'

def isValid(data, size, top, left):
	balance = 0
	weight = size-1
	for r in xrange(top, top+size):
		row = 0
		for c in xrange(left, left+size):
			row += data[r][c]
		if r == top or r == top+size-1:
			row -= data[r][left] + data[r][left+size-1]
		balance += row*weight
		weight -= 2
	if balance != 0: return False
	weight = size-1
	for c in xrange(left, left+size):
		col = 0
		for r in xrange(top, top+size):
			col += data[r][c]
		if c == left or c == left+size-1:
			col -= data[top][c] + data[top+size-1][c]
		balance += col*weight
		weight -= 2
	if balance != 0: return False
	return True

def solve(R, C, D, data):
	for size in xrange(min(R,C),2,-1):
		for top in xrange(0, R-size+1):
			for left in xrange(0, C-size+1):
				if isValid(data, size, top, left):
					return size
	return 'IMPOSSIBLE'

fin = open(name+'.in')
fout = open(name+'.out', 'w')

T = int(fin.readline().strip())
for i in xrange(T):
	R, C, D = (int(n) for n in fin.readline().strip().split(' '))
	data = []
	for j in xrange(R):
		data.append([int(n) for n in fin.readline().strip()])
	res = solve(R, C, D, data)
	fout.write('Case #%s: %s\n' % (i+1, res))

fin.close()
fout.close()
