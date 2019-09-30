#!/usr/bin/env pypy

import sys
from collections import defaultdict

def readline():
	s = raw_input().strip()
	while s == "":
		s = raw_input().strip()
	return s

def readvals():
	return map(int, readline().split())
def solve():
	"""
	Return YES iff it can be mowed in that way
	"""
	r,c = readvals()

	grid = tuple(readvals() for i in range(r))
	row_min = tuple(map(max, grid))
	col_min = tuple(map(max, zip(*grid)))
	for y in range(r):
		for x in range(c):
			if grid[y][x] != min(row_min[y], col_min[x]):
				return "NO"
	return "YES"


N = int(readline())
for i in range(N):
	sol = solve()
	print("Case #{0}: {1}".format(i+1, sol))
