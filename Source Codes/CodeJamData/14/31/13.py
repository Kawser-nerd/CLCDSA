import sys
from fractions import Fraction
from fractions import gcd

def readTest():
  line = sys.stdin.readline().strip()
  a, b = [int(_) for _ in line.split('/')]
  return Fraction(a, b)

def outputRes(test, ans):
  print 'Case #{0}: {1}'.format(test, ans)

def solve(test):
  inp = readTest()
  if inp == 1:
    outputRes(test, 0)
    return
  minn = -1
  nextPower = 1
  curr = inp
  while curr != 0 and nextPower <= 40:
    powerFrac = Fraction(1, 2 ** nextPower)
    if curr >= powerFrac:
      curr = curr - powerFrac
      if minn == -1:
        minn = nextPower

    nextPower += 1

  if curr == 0 and minn <= 40:
    outputRes(test, minn)
  else:
    outputRes(test, 'impossible')

def main():
  T = int(sys.stdin.readline().strip())
  for test in range(1, T + 1):
    solve(test)

main()
