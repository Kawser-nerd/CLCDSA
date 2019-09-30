import os, inspect
from itertools import combinations

problemName  = 'B'
# Options are 'large', 'small', and 'example'.
testCase     = 'large'
# Only relevant for small test case.
attempt      = 0

def getProbability(combination):
  X = len(combination) / 2

  probabilities = [1.0] + [0.0 for _ in xrange(X)]

  for p in combination:
    newProbabilities = [0.0 for _ in xrange(X + 1)]

    for i in xrange(X + 1):
      if i - 1 >= 0:
        newProbabilities[i] += probabilities[i - 1] * p
      newProbabilities[i] += probabilities[i] * (1 - p)

    probabilities = newProbabilities

  return probabilities[-1]

def solution(N, K, probabilities):
  probabilities = sorted(probabilities)

  if K % 2 != 0:
    return 0.0

  optimalProbability = 0.0
  finalAnswer = None

  possibilities = []
  for i in xrange(K + 1):
    possibilities.append(probabilities[:i] + probabilities[-(K-i):])
  for i in xrange(N - (K - 1)):
    possibilities.append(probabilities[i:i+K])

  for combination in possibilities:
    p = getProbability(combination)
    if p > optimalProbability:
      finalAnswer = combination
    optimalProbability = max(p, optimalProbability)

  return optimalProbability

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
    [N, K] = map(int, inputfile.readline().split(' '))
    probabilities = map(float, inputfile.readline().split(' '))
    # Get the result here
    result = solution(N, K, probabilities)

    with open(outFile, 'a') as f:
      f.write('Case #%d: %f\n' % (case, result))
