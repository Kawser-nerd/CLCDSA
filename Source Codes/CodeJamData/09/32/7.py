#!/usr/bin/env python
from sys import stdin
import math

def vecAdd(v1, v2):
  return [x1+x2 for x1,x2 in zip(v1,v2)]

def vecSub(v1, v2):
  return [x1-x2 for x1,x2 in zip(v1,v2)]

def vecDot(v1, v2):
  return sum( [x1*x2 for x1, x2 in zip(v1,v2)] )

def vecScale(v, s):
  return [x*s for x in v]

def compute(flies):
  vecAvg = [0,0,0,0,0,0]
  for vec in flies:
    vecAvg = [x+y for x,y in zip(vecAvg, vec)]
  flyCount = len(flies)
  vecAvg = [float(x) / float(flyCount) for x in vecAvg]
  x1 = vecAvg[0:3]
  x2 = vecAvg[3:]

  #num = vecDot(x1,x1) * vecDot(x2,x2) - vecDot(x1, x2)**2
  #denom = vecDot(x2,x2)

  speedSqr = vecDot(x2,x2)
  if speedSqr == 0:
    t = 0
  else:
    t = -vecDot(x1,x2) / vecDot(x2,x2)
  if t < 0:
    t = 0
  diffv = vecAdd(x1,vecScale(x2,t))
  d = math.sqrt(vecDot(diffv,diffv))

  return (d,t)


cases = int(stdin.readline())

for caseNo in xrange(1,cases+1):
  flyCount = int(stdin.readline())
  flies = []
  for flyNo in xrange(0,flyCount):
    flies.append([int(x) for x in stdin.readline().strip().split()])
  d,t = compute(flies)
  print "Case #%d: %.8f %.8f"%(caseNo, d, t)
