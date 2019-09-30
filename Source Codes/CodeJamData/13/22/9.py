#!/usr/bin/env python3

import sys

def read():
	return map(int, sys.stdin.readline().strip().split())

inf = float('inf')

mem = dict()

def genbinom(n):
	mem[(0,0)] = 1
	for i in range(1, n+1):
		mem[(i,0)] = 1
		for j in range(1, i):
			mem[(i,j)] = mem[(i-1, j-1)] + mem[(i-1, j)]
		mem[(i,i)] = 1

def binom(a, b):
	if a < 0: return 0
	if b>a: return 0
	if b == 0 or b == a: return 1
	if (a,b) in mem: return mem.get((a,b))
	mem[(a,b)] = binom(a-1, b-1) + binom(a-1, b)
	return mem[(a,b)]

def prob(a,b,c):
	if a > b+c:
		return 1
	r = 0
	q = 0
	for i in range(b+1):
		if c <= a-i <= b:
			r += binom(a, i)
		if a-i <= b:
			q += binom(a, i)

	return r/q

def test():
	n, x, y = read()
	x = abs(x)
	t = 0
	while n > (2*t+1)*(t+1):
		t += 1

	if (x+y)//2 < t: return 1.0
	if (x+y)//2 > t: return 0.0

	if x == 0:
		if n == (2*t+1)*(t+1):
			return 1.0
		else:
			return 0.0

	return prob(n - (2*t-1)*t, 2*t, y+1)


	return 0.5

genbinom(707*2)

t, = read()
for i in range(t):
	try:
		print("Case #{}: {:.7f}".format(i+1, test()))
	except:
		break
