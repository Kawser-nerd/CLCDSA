#!/usr/bin/env python

def genperm(rem):
	if rem:
		for i in rem:
			for perm in genperm(rem - set([i])):
				yield [ i ] + perm
	else:
		yield []

def permute(perm, s):
	return ''.join(s[p] for p in perm)

def compress(s):
	prev = None
	n = 0
	for c in s:
		if c != prev:
			n += 1
			prev = c
	return n

def solve():
	permSize = int(raw_input())
	data = raw_input()

	permutations = list(genperm(set(range(permSize))))

	clen = 1000000000
	for perm in permutations:
		permData = ''
		for i in range(0, len(data), permSize):
			permData += permute(perm, data[i : i + permSize])
		clen = min(clen, compress(permData))

	return clen

import psyco
psyco.full()

for case in range(int(raw_input())):
	print 'Case #%d: %s' % (case + 1, solve())
