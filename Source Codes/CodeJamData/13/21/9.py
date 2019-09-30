#!/usr/bin/env python3

import sys

def read():
	return map(int, sys.stdin.readline().strip().split())

inf = float('inf')

def solve(l, a):
	res = 0
	for t in l:
		while a <= t:
			if a == 1: return inf
			a += a-1
			res += 1
		a += t
	return res

def test():
	a, n = read()
	l = sorted(read())

	return min(solve(l[:x], a)+(n-x) for x in range(0, n+1))

t, = read()
for i in range(t):
	print("Case #{}: {}".format(i+1, test()))
