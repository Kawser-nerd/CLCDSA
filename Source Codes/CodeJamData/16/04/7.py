import os, inspect

problemName   = 'fractiles'
runOnRealData = True

def solution(K, C, S):
  necessaryTiles = (K + C - 1) / C

  if S < necessaryTiles:
    return ['IMPOSSIBLE']

  result = []
  k      = 0
  level  = 0
  tile   = 0
  while len(result) < necessaryTiles:
    tile   = (tile * K) + min(k, K - 1)
    level += 1
    k += 1
    if level == C:
      result.append(tile + 1)
      level = 0
      tile  = 0
  return result

currentDir   = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
inputString  = 'D-large.in'
outputString = problemName + ('_example_output' if not runOnRealData else '_output')
inFile       = os.path.join(currentDir, 'inputfiles', inputString)
outFile      = os.path.join(currentDir, 'outputfiles', '%s.txt' % outputString)

if os.path.exists(outFile):
  os.remove(outFile)

with open(inFile, 'r') as inputfile:
  numberOfCases = int(inputfile.readline())
  for case in xrange(1, numberOfCases + 1):
    [K, C, S] = map(int, inputfile.readline().split(' '))
    # Get the result here
    result = solution(K, C, S)

    with open(outFile, 'a') as f:
      f.write('Case #%d: %s\n' % (case, ' '.join(map(str, result))))
