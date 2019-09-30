import sys
import math
import pdb

vowels = ['a','e','i','o','u']

def docase(f,casenum):
  data = f.next().split()
  name = data[0]
  n = int(data[1])
  N = 0
  P = 0
  l = -1
  s = 0
  for i in xrange(len(name)):
    if name[i] in vowels:
      N = N+P
      P = P
      s = 0
    else:
      if s >= n-1:
        R = i-n+1-l
        N = N+P
        P = P+R
        l = i-n+1
      else:
        N = N+P
        P = P
      s += 1
  print "Case #" + str(casenum) + ": " + str(N+P)

with open(sys.argv[1],"r") as f:
  T = int(f.next())
  for k in xrange(T):
    docase(f,k+1)