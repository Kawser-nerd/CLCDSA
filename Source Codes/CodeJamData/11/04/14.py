#!/usr/bin/env python
for testCase in xrange(input()):
	n = input()
	a = map(int, raw_input().split())
	print "Case #%d: %d.000000" %(testCase + 1, sum([a[i] != i + 1 for i in xrange(n)]))
