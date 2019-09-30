#!/usr/bin/python

def readInput():
	file = open("A-large.in")
	testCaseCount = int(file.readline().rstrip())

	testCases = []

	for i in range(0, testCaseCount):
		lineCount = int(file.readline().strip())

		lines = [len(file.readline().strip().rstrip('0')) for j in range(0, lineCount)]
		testCases.append(lines)

	return testCases

def numberOfSortSteps(testCase):
	steps = 0

	stop = False

	for lineNr in range(0, len(testCase)):
		# find closest possible row
		for targetLineNr in range(lineNr, len(testCase)):
			if testCase[targetLineNr] <= lineNr + 1:
				testCase.insert(lineNr, testCase.pop(targetLineNr))
				steps += targetLineNr - lineNr
				break

	return steps

testCases = readInput()

testCaseNr = 1
for testCase in testCases:
	print 'Case #%s: %s' % (testCaseNr, numberOfSortSteps(testCase))
	testCaseNr += 1
