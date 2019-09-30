#!/usr/bin/env python3.1

from __future__ import division

import sys
import math

def calc(line):
	boosters = int(line[0])
	ready = int(line[1])
	stars = int(line[2])
	dist = [int(x) for x in line[4:]]
	dist = dist * int(math.ceil(stars / len(dist)))
	dist = dist[:stars]
	timer = 0
	i = 0
	while timer < ready:
		if ready - timer < dist[i] * 2:
			dist[i] -= (ready - timer) / 2
			timer = ready
		else:
			timer += dist[i] * 2
			i += 1
			if i == stars: return timer
	dist = list(reversed(sorted(dist[i:])))
	for i in range(boosters, len(dist)):
		dist[i] *= 2
	timer += sum(dist)
	return timer

def getints():
	return [int(x) for x in sys.stdin.readline().strip().split(" ")]

numTestCases = getints()[0]
for i in range(numTestCases):
	result = calc(getints())
	print("Case #%d: %d" % (i+1, result))

