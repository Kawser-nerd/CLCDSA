import os, inspect

problemName   = 'counting_sheep'
runOnRealData = False

def digits(N):
  return set(map(int, str(N)))

def solution(N):
  if N == 0:
    return 'INSOMNIA'

  allDigits = set(range(10))
  multiple  = 0
  while len(allDigits) > 0:
    multiple += N
    allDigits = allDigits.difference(digits(multiple))

  return multiple

currentDir   = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
inputString  = 'A-large.in'
outputString = problemName + '_output'
inFile       = os.path.join(currentDir, 'inputfiles', inputString)
outFile      = os.path.join(currentDir, 'outputfiles', '%s.txt' % outputString)

if os.path.exists(outFile):
  os.remove(outFile)

with open(inFile, 'r') as inputfile:
  numberOfCases = int(inputfile.readline())
  for case in xrange(1, numberOfCases + 1):

    N = int(inputfile.readline())

    # Get the result here
    result = solution(N)

    with open(outFile, 'a') as f:
      f.write('Case #%d: %s\n' % (case, str(result)))
