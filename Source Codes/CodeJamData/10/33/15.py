#!/usr/bin/python

import sys

def readInput():
	file = open(sys.argv[1])

	testCaseCount = int(file.readline().rstrip())
	testCases = []

	for i in xrange(testCaseCount):
		m, n = [int(x) for x in file.readline().rstrip().split()]
		grid = [parseLine(file.readline().rstrip()) for x in xrange(m)]

		testCases.append((m, n, grid))

	return testCases

def parseLine(line):
	fields = []
	for char in line:
		num = int(char, 16)
		fields.append(num & 8 == 8)
		fields.append(num & 4 == 4)
		fields.append(num & 2 == 2)
		fields.append(num & 1 == 1)

	return fields

def solve((m, n, grid)):
	taken = [[False] * n for x in xrange(m)]
	boards = [0] * (min(m, n) + 1)

	for size in xrange(min(m, n), 0, -1):
		for row in xrange(m - size + 1):
			for column in xrange(n - size + 1):
				if isAvailable(grid, taken, row, column, size):
					boards[size] += 1
					take(taken, row, column, size)

	answer = [(index, boards[index]) for index in xrange(min(m, n), 0, -1) if boards[index] != 0]

	return "%d\n%s" % (len(answer), "\n".join("%d %d" % item for item in answer))


def isAvailable(grid, taken, startRow, startColumn, size):
	color = grid[startRow][startColumn]

	for row in xrange(startRow, startRow + size):
		expectedColor = color

		for column in xrange(startColumn, startColumn + size):
			if taken[row][column]:
				return False

			if grid[row][column] != expectedColor:
				return False

			expectedColor = not expectedColor

		color = not color

	return True

def take(taken, startRow, startColumn, size):
	for row in xrange(startRow, startRow + size):
		for column in xrange(startColumn, startColumn + size):
			taken[row][column] = True

testCases = readInput()

testCaseNr = 1
for testCase in testCases:
	print 'Case #%d: %s' % (testCaseNr, solve(testCase))
	testCaseNr += 1
