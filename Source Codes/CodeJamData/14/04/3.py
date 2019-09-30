from collections import deque
from bisect import bisect
from copy import copy

def main():
  f = open('D.in', 'r')
  T = int (f.readline())

  for t in range(1, T+1):
    print 'Case #' + str(t) + ':',
    N = int (f.readline())
    p1 = getBlocks(f)
    p2 = getBlocks(f)
    normalPoints = getNormalPoints(copy(p1), copy(p2))
    deceitfulPoints = getDeceitfulPoints(copy(p1), copy(p2))
    print deceitfulPoints, normalPoints

def getBlocks(f):
  return deque(sorted(map(float, f.readline().split())))

def getNormalPoints(p1, p2):
  points = 0
  while (len(p1) > 0):
    v1 = p1.popleft()
    i = bisect(p2, v1)
    if i == len(p2): # can't win
      p2.popleft() # use the lightest
      points += 1    
    else:
      p2.remove(p2[i]) # win
  return points

def getDeceitfulPoints(p1, p2):
  points = len(p1)
  while (not check(p1, p2)):
    # sacrifice the lightest brick for the heaviest one
    p1.popleft()
    p2.pop()
    points -= 1
  return points

def check(p1, p2):
  for i in xrange(len(p1)):
    if p1[i] < p2[i]:
      return False
  return True

if __name__ == "__main__":
    main()
