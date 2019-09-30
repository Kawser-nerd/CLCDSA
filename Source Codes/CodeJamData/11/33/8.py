#!/usr/bin/python

import sys

def readInput():
  file = open(sys.argv[1])

  testCaseCount = int(file.readline())

  testCases = []
  for x in xrange(testCaseCount):
    N, L, H = [int(x) for x in file.readline().split()]

    notes = [int(x) for x in file.readline().split()]

    testCases.append((L, H, notes))
  
  return testCases

def solve((L, H, notes)):
  for x in xrange(L, H + 1):
    found = True
    for note in notes:
      if x % note != 0 and note % x != 0:
        found = False
        break
    if found:
      return x

  return 'NO'

testCases = readInput()

testCaseNr = 1
for testCase in testCases:
  print 'Case #%d: %s' % (testCaseNr, solve(testCase))
  testCaseNr += 1
