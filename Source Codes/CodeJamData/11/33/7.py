#!/usr/bin/env python3.1

from __future__ import division

import sys

def calc(a, b):
	n, l, h = a
	freq = b
	for i in range(l, h+1):
		harmony = True
		for f in freq:
			if not (f % i == 0 or i % f == 0):
				harmony = False
				break
		if harmony:
			return "%d" % i
	return "NO"

def getints():
	return [int(x) for x in sys.stdin.readline().strip().split(" ")]

numTestCases = getints()[0]
for i in range(numTestCases):
	result = calc(getints(), getints())
	print("Case #%d: %s" % (i+1, result))

