#!/usr/bin/env pypy
from cj import jam

def read(reader):
	return reader(int, int)

def contains(n, a, b):
	m = n * (n + 1) / 2
	mod = m % 2
	return a <= m  and  a % 2 == mod  and  b <= m  and  b % 2 == mod

def move(step, n, x, y):
	if step == 'N':
		x1, y1 = x, y - n
	if step == 'S':
		x1, y1 = x, y + n
	if step == 'E':
		x1, y1 = x - n, y
	if step == 'W':
		x1, y1 = x + n, y
	a, b = abs(x1 + y1), abs(x1 - y1)
	return x1, y1, a, b

def solve(x, y):
	a, b = abs(x + y), abs(x - y)
	n = 1
	while not contains(n, a, b):
		n += 1
	dirs = 'NSEW'
	steps = []
	for i in xrange(n, 0, -1):
		for step in dirs:
			x1, y1, a, b = move(step, i, x, y)
			if contains(i - 1, a, b):
				x, y = x1, y1
				steps.append(step)
				break
	return ''.join(reversed(steps))

jam(read, solve)
