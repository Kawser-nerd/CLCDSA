#!/usr/bin/python
# -*- coding: utf-8 -*-

from __future__ import division

import sys
import math

lines = sys.stdin.readlines()

C = int(lines[0])

def solve(Rs):
	field = {}
	for r in Rs:
		for y in range(r[1], r[3]+1):
			for x in range(r[0], r[2]+1):
				field[(x, y)] = True
	turns = 0
	while len(field):
		turns += 1
		will_spawn = []
		will_die = []
		for (x,y) in field:
			if field.get((x, y-1)) or field.get((x-1, y)):
				pass
			else:
				will_die.append((x,y))
			if field.get((x+1,y-1)):
				will_spawn.append((x+1,y))
			if field.get((x-1,y+1)):
				will_spawn.append((x,y+1))
		for p in will_die: field.pop(p)
		for p in will_spawn: field[p] = True
	return turns

idx = 1
for t in range(1, C + 1):
	R = int(lines[idx])
	Rs = []
	for r in range(R):
		Rs.append([int(x) for x in lines[idx + 1 + r].split()])
	idx += R + 1
	answer = solve(Rs)
	print "Case #%d: %s" % (t, answer)
