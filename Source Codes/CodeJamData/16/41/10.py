import os, inspect

problemName  = 'A'
# Options are 'large', 'small', and 'example'.
testCase     = 'large'
# Only relevant for small test case.
attempt      = 0

cache = {}

def optimalString(finalValue, X):
  if X in cache:
    return cache[(finalValue, X)]

  if X == 1:
    return finalValue

  twoValues = {'R' : ('R', 'S'), 'S' : ('S', 'P'), 'P' : ('P', 'R')}[finalValue]
  string1 = optimalString(twoValues[0], X / 2)
  string2 = optimalString(twoValues[1], X / 2)

  if string1 < string2:
    result = string1 + string2
  else:
    result = string2 + string1

  cache[(finalValue, X)] = result
  return result

def getStart(R, P, S):
  X = R + P + S
  possibleEndings = [{'R' : 1, 'S' : 0, 'P' : 0}, {'R' : 0, 'S' : 1, 'P' : 0}, {'R' : 0, 'S' : 0, 'P' : 1}]
  value = 1

  while value < X:
    value *= 2
    newPossibleEndings = []
    for possibleEnding in possibleEndings:
      newDictionary = {}
      newDictionary['R'] = possibleEnding['P'] + possibleEnding['R']
      newDictionary['P'] = possibleEnding['S'] + possibleEnding['P']
      newDictionary['S'] = possibleEnding['R'] + possibleEnding['S']
      newPossibleEndings.append(newDictionary)

    possibleEndings = newPossibleEndings

  for possibleEnding in zip(possibleEndings, ['R', 'S', 'P']):
    dictionary = possibleEnding[0]
    startingValue = possibleEnding[1]
    if dictionary['R'] == R and dictionary['S'] == S and dictionary['P'] == P:
      return startingValue

  return None

def solution(N, R, P, S):
  result = getStart(R, P, S)

  if result is None:
    return 'IMPOSSIBLE'

  return optimalString(result, R + P + S)

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
    [N, R, P, S] = map(int, inputfile.readline().split(' '))

    # Get the result here
    result = solution(N, R, P, S)

    with open(outFile, 'a') as f:
      f.write('Case #%d: %s\n' % (case, result))
