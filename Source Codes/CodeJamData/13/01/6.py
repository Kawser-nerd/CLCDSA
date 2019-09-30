#!/usr/bin/env pypy

import sys
from collections import defaultdict

def readline():
	s = raw_input().strip()
	while s == "":
		s = raw_input().strip()
	return s

def didwin(grid, c):
	def isgood(x):
		return x == c or x == 'T'
	for i in range(4):
		if all(isgood(grid[i][x]) for x in range(4)):
			return True
		if all(isgood(grid[y][i]) for y in range(4)):
			return True
	if all(isgood(grid[i][i]) for i in range(4)):
		return True
	if all(isgood(grid[i][4-i-1]) for i in range(4)):
		return True

def solve():
	grid = tuple(readline() for i in range(4))
	if didwin(grid, 'X'):
		return "X won"
	elif didwin(grid, 'O'):
		return "O won"
	elif any(grid[r][c] == '.' for r in range(4) for c in range(4)):
		return "Game has not completed"
	else:
		return "Draw"

N = int(readline())
for i in range(N):
	sol = solve()
	print("Case #{0}: {1}".format(i+1, sol))
