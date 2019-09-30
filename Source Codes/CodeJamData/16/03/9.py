import os, inspect

problemName   = 'coin_jam'
runOnRealData = True

def biggestFactor(N):
  for i in xrange(2, N):
    if N % i == 0:
      return N / i
  return 1

def binary(N):
  return bin(N)[2:]

def convertToBaseTen(string, base):
  value = 0
  for d in string:
    value = base * value + int(d)
  return value

def solution(N, J):
  F      = biggestFactor(N)
  result = []

  for x in xrange(2**(F-2), 2**(F-1)):
    B   = binary(x * 2 + 1)
    row = [B * (N / F)]
    for base in xrange(2, 11):
      row.append(convertToBaseTen(B, base))
    result.append(row)
    if len(result) >= J:
      return result

currentDir   = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
inputString  = 'C-large.in'
outputString = problemName + ('_example_output' if not runOnRealData else '_output')
inFile       = os.path.join(currentDir, 'inputfiles', inputString)
outFile      = os.path.join(currentDir, 'outputfiles', '%s.txt' % outputString)

if os.path.exists(outFile):
  os.remove(outFile)

with open(inFile, 'r') as inputfile:
  numberOfCases = int(inputfile.readline())
  for case in xrange(1, numberOfCases + 1):
    [N, J] = map(int, inputfile.readline().split(' '))
    # Get the result here
    result = solution(N, J)

    with open(outFile, 'a') as f:
      f.write('Case #%d:\n' % case)
      for line in result:
        f.write(' '.join(map(str, line)) + '\n')
