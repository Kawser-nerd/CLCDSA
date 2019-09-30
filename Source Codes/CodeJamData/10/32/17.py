#!/usr/bin/python

import sys
import math

def readInput():
	file = open(sys.argv[1])

	testCaseCount = int(file.readline().rstrip())

	testCases = [[int(x) for x in file.readline().rstrip().split()] for line in xrange(testCaseCount)]
	
	return testCases

def solve((L, P, C)):
	"""
	L = known success capacity
	P = known failure capacity
	C = desired factor (a * C fails (>= P))
	"""

	brackets = 1
	while L * C < P:
		L *= C
		brackets += 1

	return int(math.ceil(math.log(brackets, 2)))
	
testCases = readInput()

testCaseNr = 1
for testCase in testCases:
	print 'Case #%d: %s' % (testCaseNr, solve(testCase))
	testCaseNr += 1
