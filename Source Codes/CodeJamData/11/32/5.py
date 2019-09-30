#!/usr/bin/python

import sys

def readInput():
  file = open(sys.argv[1])

  testCaseCount = int(file.readline())

  testCases = [[int(x) for x in file.readline().split()] for line in xrange(testCaseCount)]
  
  return testCases

def solve(line):
  L,t,N,C = line[:4]
  stars = line[4:]

  time = 0
  benefitWithBoosters = []
  for star in xrange(N):
    if time >= t:
      benefit = stars[star % C]
    elif time + (stars[star % C] * 2) >= t:
      distanceSlow = (t - time) / 2
      distanceFast = stars[star % C] - distanceSlow
      benefit = distanceFast
      time += distanceSlow * 2 + distanceFast
    else:
      benefit = 0
      time += stars[star % C] * 2

    benefitWithBoosters.append((benefit, star))
  
  benefitWithBoosters.sort()

  built = set()

  while L != 0:
    duration, star = benefitWithBoosters.pop()
    built.add(star)
    L -= 1

  time = 0
  for star in xrange(N):
    if star in built:
      if time >= t:
        time += stars[star % C]
      elif time + (stars[star % C] * 2) >= t:
        distanceSlow = (t - time) / 2
        distanceFast = stars[star % C] - distanceSlow
        time += distanceSlow * 2 + distanceFast
      else:
        time += stars[star % C] * 2
    else:
      time += stars[star % C] * 2

  return time

testCases = readInput()

testCaseNr = 1
for testCase in testCases:
  print 'Case #%d: %s' % (testCaseNr, solve(testCase))
  testCaseNr += 1
