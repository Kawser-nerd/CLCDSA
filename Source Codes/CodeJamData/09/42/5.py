#!/usr/bin/python

import pprint

# more than 50 (limit for R)
failure = 100

class B(object):
	def __init__(self, fallDistance):
		self.bestLength = failure
		self.fallDistance = fallDistance

	def findShortest(self, testCase):
		self.step(testCase, 0, 0, 0)
		return self.bestLength

	def step(self, testCase, x, y, length):
		#print x, y, length, 'step'
		
		self.stepDirectionFall(testCase, x, y, length, -1)
		self.stepDirectionFall(testCase, x, y, length, 1)
		self.stepDirectionDig(testCase, x, y, length, -1)
		self.stepDirectionDig(testCase, x, y, length, 1)

	def stepDirectionDig(self, testCase, x, y, length, direction):
		#print x, y, length, 'stepDirectionDig'

		if 0 <= x - direction < len(testCase[0]):
			if not testCase[y + 1][x - direction] and testCase[y][x - direction]:
				self.dig(testCase, x, y, length, -direction)

		if not 0 <= x + direction < len(testCase[0]):
			return
		
		if not testCase[y + 1][x + direction] and testCase[y][x + direction]:
			self.dig(testCase, x, y, length, direction)
		else:
			# can't jump over holes
			return

		self.stepDirectionDig(testCase, x + direction, y, length, direction)

	def stepDirectionFall(self, testCase, x, y, length, direction):
		#print x, y, length, 'stepDirectionFall'

		if not 0 <= x + direction < len(testCase[0]):
			return
		
		# can't move into rock
		if not testCase[y][x + direction]:
			return

		if testCase[y + 1][x + direction]:
			self.fall(testCase, x + direction, y + 1, length)
		else:
			self.stepDirectionFall(testCase, x + direction, y, length, direction)

	def dig(self, testCase, x, y, length, direction):
		#print x, y, length, 'dig'


		if length + 1 >= self.bestLength:
			# already found an equal or better path
			return

		newTestCase = [a[:] for a in testCase]
		testCase = newTestCase

		if testCase[y + 1][x + direction]:
			raise Exception("Error: tried to dig air")
		if not testCase[y][x + direction]:
			raise Exception("Error: tried to dig under rock")

		testCase[y + 1][x + direction] = True

		self.step(testCase, x, y, length + 1)

	def fall(self, testCase, x, y, length):
		distance = 0
		while True:
			distance += 1
			if distance > self.fallDistance:
				#print x, y, length, "fall dead"
				return

			if y + distance == len(testCase):
				#print x, y, length, "fall win"
				self.bestLength = length
				return

			if not testCase[y+distance][x]:
				break
		
		#print x, y, length, "fall rock"
		self.step(testCase, x, y + distance - 1, length)

def readInput():
	file = open("B-small-attempt2.in")
	testCaseCount = int(file.readline().rstrip())

	testCases = []

	for i in range(0, testCaseCount):
		height, width, fallDistance = [int(i) for i in file.readline().rstrip().split(' ')]

		cave = []
		for i in range(0, height):
			cave.append([c == '.' for c in file.readline().rstrip()])
		testCases.append((fallDistance, cave))

	return testCases

testCases = readInput()

testCaseNr = 1
for fallDistance, testCase in testCases:
	result = B(fallDistance).findShortest(testCase)

	if result != failure:
		print "Case #%s: Yes %s" % (testCaseNr, result)
	else:
		print "Case #%s: No" % testCaseNr

	testCaseNr += 1
