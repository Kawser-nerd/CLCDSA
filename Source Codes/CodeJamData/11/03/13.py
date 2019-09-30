#!/bin/usr/env python
for testCase in xrange(input()):
	n = input()
	c = map(int, raw_input().split())
	a = "Case #%d: " %(testCase + 1)
	if reduce(lambda x, y: x ^ y, c) != 0:
		a += "NO"
	else:
		a += str(sum(c) - min(c))
	print a
