import sys
import math
import string
import pdb

def docase(f,casenum):
  data = f.next().split()
  X = int(data[0])
  Y = int(data[1])
  abssum = abs(X)+abs(Y)
  n = int(math.sqrt(2*abssum))
  found = False
  while not found:
    val = n*(n+1)/2
    if val >= abssum and (val-abssum)%2 == 0:
      found = True
      break
    n += 1
  result = ""
  result = []
  for i in xrange(n,0,-1):
    if abs(X) > abs(Y):
      if X > 0:
        result.append("E")
        X -= i
      else:
        result.append("W")
        X += i
    else:
      if Y > 0:
        result.append("N")
        Y -= i
      else:
        result.append("S")
        Y += i
  result.reverse()
  strres = "".join(result)
  print "Case #" + str(casenum) + ": " + strres

with open(sys.argv[1],"r") as f:
  T = int(f.next())
  for k in xrange(T):
    docase(f,k+1)