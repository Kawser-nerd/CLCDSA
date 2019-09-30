# coding=utf-8

import os, sys, time, random
time.clock()

sys.stdin = open('A-large.in')
sys.stdout = open('A-large.out', 'w')

def Work():
	R, C = map(int, input().split())
	grid = []
	for i in range(R):
		grid.append(input())
	ee = [  ['' for i in range(C)] for j in range(R)]
	for j in range(C):
		for i in range(R):
			if grid[i][j] == '.': continue
			ee[i][j] += '^'
			break
		for i in range(R-1, -1, -1):
			if grid[i][j] == '.': continue
			ee[i][j] += 'v'
			break
	for i in range(R):
		for j in range(C):
			if grid[i][j] == '.': continue
			ee[i][j] += '<'
			break
		for j in range(C-1, -1, -1):
			if grid[i][j] == '.': continue
			ee[i][j] += '>'
			break
	ans = 0
	for i in range(R):
		for j in range(C):
			if len(ee[i][j]) == 4: return 'IMPOSSIBLE'
			if grid[i][j] in ee[i][j]: ans += 1
	return str(ans)

if __name__ == '__main__':
	T = int(input())
	for i in range(T): 
		print('Case #%d: %s' % (i+1, Work()))
	sys.stderr.write('completed %.3f\n' % time.clock())
	
	
