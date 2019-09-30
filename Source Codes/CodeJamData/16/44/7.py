import os, inspect
from itertools import combinations

problemName  = 'D'
# Options are 'large', 'small', and 'example'.
testCase     = 'small'
# Only relevant for small test case.
attempt      = 0

def isValidSolutionHelper(people, machines, matrix):
  if len(people) == 0:
    return True

  for person in people:
    noValidMachines = True
    for machine in machines:
      if matrix[person][machine] == 1:
        if not isValidSolutionHelper(people.difference(set([person])), machines.difference(set([machine])), matrix):
          return False
        noValidMachines = False
    if noValidMachines:
      return False
  return True

def isValidSolution(matrix):
  return isValidSolutionHelper(set(range(len(matrix))), set(range(len(matrix))), matrix)

def solution(N, matrix):
  if isValidSolution(matrix):
    return 0
  emptySlots = []
  for i in xrange(N):
    for j in xrange(N):
      if matrix[i][j] == 0:
        emptySlots.append((i, j))
  for result in xrange(len(emptySlots) + 1):
    for possibleTeaching in combinations(emptySlots, result):
      matrixCopy = [list(x) for x in matrix]
      for (a, b) in possibleTeaching:
        matrixCopy[a][b] = 1
      if isValidSolution(matrixCopy):
        return result
  return -1

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
    N = int(inputfile.readline())
    matrix = []
    for _ in xrange(N):
      matrix.append(map(int, list(inputfile.readline().strip())))

    # Get the result here
    result = solution(N, matrix)

    with open(outFile, 'a') as f:
      f.write('Case #%d: %d\n' % (case, result))
