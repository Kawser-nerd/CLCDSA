#!/usr/bin/python

import sys

def readInput():
	file = open(sys.argv[1])

	testCaseCount = int(file.readline().rstrip())
	testCases = []

	for i in xrange(testCaseCount):
		n = int(file.readline().rstrip())
		As = []
		Bs = []
		for j in xrange(n):
			a, b = [int(x) for x in file.readline().rstrip().split()]
			As.append(a)
			Bs.append(b)

		testCases.append((n, As, Bs))

	return testCases

def solve((n, As, Bs)):
	intersections = 0

	for i in xrange(n):
		for j in xrange(n):
			if i == j:
				continue

			# start below, end above
			if As[i] < As[j] and Bs[i] > Bs[j]:
				intersections += 1

			# start above, end below
			elif As[i] > As[j] and Bs[i] < Bs[j]:
				intersections += 1

	# intersections were counted twice
	return intersections / 2

testCases = readInput()

testCaseNr = 1
for testCase in testCases:
	print 'Case #%d: %s' % (testCaseNr, solve(testCase))
	testCaseNr += 1
