#!/usr/bin/python

import sys,re

if len(sys.argv) != 2:
  print "usage: " + sys.argv[0] + " infile"
  sys.exit()
infile = open(sys.argv[1], 'r')

debugprint = 0 # 0 to suppress debugging output

def debug(str, lvl=5):
  if debugprint > lvl: print "[DEBUG]", str

def isbalanced(weights, x, y, size):
  xwt = 0
  ywt = 0
  wt = 0
  for i in range(x, x+size):
    for j in range(y, y+size):
      wt = wt + weights[i][j]
      xwt = xwt + (i-x)*weights[i][j]
      ywt = ywt + (j-y)*weights[i][j]
  debug([wt,xwt,ywt])
  wt = wt - weights[x][y] - weights[x+size-1][y] - weights[x][y+size-1] - weights[x+size-1][y+size-1]
  xwt = xwt - (size-1)*weights[x+size-1][y] - (size-1)*weights[x+size-1][y+size-1]
  ywt = ywt - (size-1)*weights[x][y+size-1] - (size-1)*weights[x+size-1][y+size-1]
  debug([wt,xwt,ywt])
  #xmid = round(1.*xwt/wt, 6)
  #ymid = round(1.*ywt/wt, 6)
  #debug([x, y, size, wt, xwt, ywt, xmid, ymid])
  # avoid messy floathing points
  #if xmid == (size-1.)/2 and ymid == (size-1.)/2:
  #  return True
  #return False
  if 2*xwt - wt*(size-1) != 0:
    return False
  if 2*ywt - wt*(size-1) != 0:
    return False
  return True


def ispossible(weights, R, C, size):
  if size > R or size > C: return False
  for i in range(0, R-size+1):
    for j in range(0, C-size+1):
      if isbalanced(weights, i, j, size):
        return True
  return False

def handleonecase(line1):
  #TODO
  debug("new case")
  R = int(line1[0])
  C = int(line1[1])
  D = int(line1[2])
  weights = [];
  for i in range(0,R):
    data = infile.readline().strip()
    weights.append(range(0,C));
    for j in range(0,C):
      weights[i][j] = int(data[j])
  debug(weights)
  maxsize = R + 1
  while True:
    maxsize = maxsize - 1
    if maxsize == 2:
      return "IMPOSSIBLE"
    if ispossible(weights, R, C, maxsize):
      return maxsize
  return len(line1)

maxcases = 0
casenum = 0

line = infile.readline().strip()
maxcases = int(line)
while line:
  casenum = casenum + 1
  if casenum > maxcases: break
  line1 = infile.readline().strip().split()
#  line2 = infile.readline().strip().split()
  result = handleonecase(line1)
  print "Case #" + str(casenum) + ": " + str(result)




