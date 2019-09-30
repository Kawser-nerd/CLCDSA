import os, inspect

problemName  = 'A'
# Options are 'large', 'small', and 'example'.
testCase     = 'large'
# Only relevant for small test case.
attempt      = 0

def solution(preferences):
  totalTaken = 0
  holding    = []
  points     = 0
  for c in preferences:
    if len(holding) == 0 or holding[-1] != c:
      if totalTaken == len(preferences) / 2:
        holding.pop()
        points += 5
      else:
        holding.append(c)
        totalTaken += 1
    else:
      holding.pop()
      points += 10
  return points

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

    # Get the result here
    result = solution(inputfile.readline().strip())

    with open(outFile, 'a') as f:
      f.write('Case #%d: %d\n' % (case, result))
