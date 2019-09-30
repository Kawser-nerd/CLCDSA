#!/usr/bin/env python3

import sys

def read():
	return map(int, sys.stdin.readline().strip().split())

t, = read()

def s(x):
	return x*(x+1)//2

def cost(a, b, n):
	x = b-a
	return s(n) - s(x)

MOD = 1000002013

def test():
	n, m = read()
	ev = []
	stos = []

	price = 0
	
	for i in range(m):
		a,b,c = read()
		price += c * cost(a, b, n)
		ev.append((a,-c))
		ev.append((b, c))
	ev.sort()

	for t, a in ev:
		if a < 0:
			stos.append([t, -a])
		else:
			while a > 0:
				if stos[-1][1] > a:
					stos[-1][1] -= a
					price -= a * cost(stos[-1][0], t, n)
					a = 0
				else:
					ot, oa = stos.pop()
					price -= oa * cost(ot, t, n)
					a -= oa

	return price % MOD

for i in range(1, t+1):
	print('Case #{}: {}'.format(i, test()))
