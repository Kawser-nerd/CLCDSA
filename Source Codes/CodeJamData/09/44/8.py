#!/usr/bin/python

def readInput():
	file = open("D-small-attempt0.in")
	testCaseCount = int(file.readline().rstrip())

	testCases = []

	for i in range(0, testCaseCount):
		plantCount = int(file.readline().rstrip())
		plants = []
		for j in range(0, plantCount):
			plants.append([int(k) for k in file.readline().rstrip().split(' ')])
		
		testCases.append(plants)

	return testCases

def getMinSize(testCase):
	if len(testCase) == 1:
		return testCase[0][2]
	if len(testCase) == 2:
		if testCase[0][2] > testCase[1][2]:
			return testCase[0][2]
		else:
			return testCase[1][2]

	minSize = 1000
	for i in range(0, 3):
		for j in range(0, 3):
			for k in range(0, 3):

				if i == j:
					continue
				if i == k:
					continue
				if j == k:
					continue

				xDiff = testCase[i][0] - testCase[j][0]
				yDiff = testCase[i][1] - testCase[j][1]

				size = (((xDiff ** 2) + (yDiff ** 2)) ** 0.5)

				size += testCase[i][2] + testCase[j][2]
				if size < testCase[k][2]:
					size = testCase[k][2]

				if minSize > size:
					minSize = size

	return minSize / 2

testCases = readInput()

testCaseNr = 1
for testCase in testCases:
	print "Case #%s: %f" % (testCaseNr, getMinSize(testCase))
	testCaseNr += 1
