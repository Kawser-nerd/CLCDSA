import os, inspect

problemName   = 'pancakes'
runOnRealData = True

def solution(string):
  current = '+'
  flips   = 0
  for c in string[::-1]:
    if c != current:
      flips  += 1
      current = c
  return flips

currentDir   = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
inputString  = 'B-large.in'
outputString = problemName + ('_example_output' if not runOnRealData else '_output')
inFile       = os.path.join(currentDir, 'inputfiles', inputString)
outFile      = os.path.join(currentDir, 'outputfiles', '%s.txt' % outputString)

if os.path.exists(outFile):
  os.remove(outFile)

with open(inFile, 'r') as inputfile:
  numberOfCases = int(inputfile.readline())
  for case in xrange(1, numberOfCases + 1):
    string = inputfile.readline().strip()
    # Get the result here
    result = solution(string)

    with open(outFile, 'a') as f:
      f.write('Case #%d: %d\n' % (case, result))
