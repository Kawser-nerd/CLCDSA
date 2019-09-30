#!/usr/bin/python

import sys

def readInput():
  file = open(sys.argv[1])

  testCaseCount = int(file.readline())

  testCases = []
  for x in xrange(testCaseCount):
    R, C = [int(x) for x in file.readline().split()]

    picture = [[a for a in file.readline().rstrip()] for x in xrange(R)]

    testCases.append((R, C, picture))
  
  return testCases

def solve((R, C, picture)):
  for row in xrange(R):
    for column in xrange(C):
      if picture[row][column] != '#':
        continue

      if row == R - 1 or column == C - 1 or picture[row][column + 1] != '#' or picture[row + 1][column] != '#' or picture[row + 1][column + 1] != '#':
        return ['Impossible']

      picture[row][column] = '/'
      picture[row][column + 1] = '\\'
      picture[row + 1][column] = '\\'
      picture[row + 1][column + 1] = '/'
    
  return [''.join(x) for x in picture]

testCases = readInput()

testCaseNr = 1
for testCase in testCases:
  print 'Case #%d: \n%s' % (testCaseNr, '\n'.join(solve(testCase)))
  testCaseNr += 1
