import os, inspect
from itertools import product

problemName  = 'C'
# Options are 'large', 'small', and 'example'.
testCase     = 'small'
# Only relevant for small test case.
attempt      = 0

def getAdjacentPositions(x, y, c, R, C, value):
  result = []

  if c == 4 and y > 0:
    result.append((x, y-1, 2))
  if c == 2 and y < C - 1:
    result.append((x, y+1, 4))

  if c == 3 and x < R - 1:
    result.append((x+1, y, 1))
  if c == 1 and x > 0:
    result.append((x-1, y, 3))

  if c == 1 and value == '/':
    result.append((x, y, 4))
  if c == 1 and value == '\\':
    result.append((x, y, 2))
  if c == 2 and value == '/':
    result.append((x, y, 3))
  if c == 2 and value == '\\':
    result.append((x, y, 1))
  if c == 3 and value == '/':
    result.append((x, y, 2))
  if c == 3 and value == '\\':
    result.append((x, y, 4))
  if c == 4 and value == '/':
    result.append((x, y, 1))
  if c == 4 and value == '\\':
    result.append((x, y, 3))
  return result

def checkSolution(R, C, courtiers, solution):
  pairedCourtier = {}
  for i in xrange(len(courtiers) / 2):
    pairedCourtier[courtiers[2 * i]] = courtiers[2 * i + 1]
    pairedCourtier[courtiers[2 * i + 1]] = courtiers[2 * i]

  occupiedLocations = {}
  courtierIndex = 1
  for i in xrange(C):
    occupiedLocations[(0, i, 1)] = courtierIndex
    courtierIndex += 1
  for i in xrange(R):
    occupiedLocations[(i, C - 1, 2)] = courtierIndex
    courtierIndex += 1
  for i in xrange(C):
    occupiedLocations[(R - 1, C - 1 - i, 3)] = courtierIndex
    courtierIndex += 1
  for i in xrange(R):
    occupiedLocations[(R - 1 - i, 0, 4)] = courtierIndex
    courtierIndex += 1

  for (startingPos, courtierIndex) in occupiedLocations.iteritems():
    unParsed = set([startingPos])
    parsed   = set()
    while len(unParsed) > 0:
      (x, y, c) = unParsed.pop()
      parsed.add((x, y, c))
      if (x, y, c) in occupiedLocations and occupiedLocations[(x, y, c)] != courtierIndex and occupiedLocations[(x, y, c)] != pairedCourtier[courtierIndex]:
        return False
      adjacentPositions = getAdjacentPositions(x, y, c, R, C, solution[x + 1][y + 1])
      for adjacentPosition in adjacentPositions:
        if adjacentPosition not in parsed and adjacentPosition not in unParsed:
          unParsed.add(adjacentPosition)

  return True

def getBaseSolution(R, C, courtiers):
  baseSolution = [['' for _ in xrange(C + 2)] for _ in xrange(R + 2)]
  courtierIndex = 1
  for i in xrange(C):
    baseSolution[0][i + 1] = courtierIndex
    courtierIndex += 1
  for i in xrange(R):
    baseSolution[i + 1][-1] = courtierIndex
    courtierIndex += 1
  for i in xrange(C):
    baseSolution[-1][C - i] = courtierIndex
    courtierIndex += 1
  for i in xrange(R):
    baseSolution[R - i][0] = courtierIndex
    courtierIndex += 1
  return baseSolution

def parseSolution(R, C, newSolution):
  result = []
  for i in xrange(R):
    result.append(''.join(newSolution[i + 1][1:-1]))
  return '\n'.join(result)

def solution(R, C, courtiers):
  baseSolution = getBaseSolution(R, C, courtiers)
  for value in product('/\\', repeat = R * C):
    newSolution = [list(x) for x in baseSolution]
    for i in xrange(R):
      for j in xrange(C):
        newSolution[i + 1][j + 1] = value[i * C + j]
    if checkSolution(R, C, courtiers, newSolution):
      return parseSolution(R, C, newSolution)
  return 'IMPOSSIBLE'

currentDir   = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
if testCase in ['large', 'example']:
  inputString  = problemName + ('-%s' % testCase)
  outputString = problemName + ('-%s' % testCase)
else:
  inputString  = problemName + ('-%s-attempt%d' % (testCase, attempt))
  outputString = problemName + ('-%s' % testCase)

inFile       = os.path.join(currentDir, 'inputfiles', '%s.in' % inputString)
outFile      = os.path.join(currentDir, 'outputfiles', '%s.out' % outputString)

if os.path.exists(outFile):
  os.remove(outFile)

with open(inFile, 'r') as inputfile:
  numberOfCases = int(inputfile.readline())
  for case in xrange(1, numberOfCases + 1):
    [R, C] = map(int, inputfile.readline().split(' '))
    courtiers = map(int, inputfile.readline().split(' '))

    # Get the result here
    result = solution(R, C, courtiers)

    with open(outFile, 'a') as f:
      f.write('Case #%d:\n%s\n' % (case, result))
