#!/usr/bin/python
# -*- coding: utf-8 -*-

from __future__ import division

import sys
import math

lines = sys.stdin.readlines()

T = int(lines[0])

done = {}

def tests_needed(L, P, C):
	if P <= L*C: return 0
	if L != 1: return tests_needed(1, int(math.ceil(P/L)), C)
	ret = 0
	while P > L*C:
		C *= C
		ret += 1
	return ret

idx = 1
for t in range(1, T + 1):
	l = lines[t].split()
	l = [int(x) for x in l]
	L = l[0]
	P = l[1]
	C = l[2]
	done = {}
	answer = tests_needed(L, P, C)
	#for d in sorted(done):
		#print >> sys.stderr, d, done[d]
	print "Case #%d: %s" % (t, answer)
