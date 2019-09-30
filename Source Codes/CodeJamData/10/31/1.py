#!/usr/bin/python
# -*- coding: utf-8 -*-

from __future__ import division

import sys

lines = sys.stdin.readlines()

T = int(lines[0])

def simple_intersect(a, b):
	if a[0] < b[0]:
		return a[1] > b[1]
	elif a[0] > b[0]:
		return a[1] < b[1]
	else:
		print("error", a, b)
		sys.exit(0)

idx = 1
for t in range(1, T + 1):
	N = int(lines[idx])
	ropes = []
	for n in range(N):
		l = lines[idx + 1 + n].split()
		l = [int(x) for x in l]
		ropes.append((l[0], l[1]))
	answer = 0
	for i in range(N):
		for j in range(i + 1, N):
			if simple_intersect(ropes[i], ropes[j]):
				answer += 1
	idx += 1 + N
	print "Case #%d: %s" % (t, answer)
