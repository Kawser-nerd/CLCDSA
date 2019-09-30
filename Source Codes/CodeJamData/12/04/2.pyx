#!/usr/bin/env python
from fractions import gcd #, Fraction as fr
from gmpy import mpq as fr

import math

def nexthalf(x):
  return fr((x*2+1)//1,2)
  #return math.floor(x*2+1)/2.
def nextpos(x,dx):
  return nexthalf(x) if dx>0 else -nexthalf(-x)

def blah(d,X):
  for i,line in enumerate(X):
    if 'X' in line:
      initr,initc = i,line.index('X')
  ans = 0
  for (dr,dc) in ((1,0),(0,1),(-1,0),(0,-1)):
    r,c=initr,initc
    dist = 0
    for j in xrange(d/2+1):
      r,c = r+dr,c+dc
      if X[r][c]=='#':
        dist += 1
        break
      else:
        dist += 2
    if dist<=d:
      ans += 1

  for origdr in xrange(-d,d+1):
    if origdr==0: continue
    for origdc in xrange(-d,d+1):
      if origdc==0 or abs(gcd(origdr,origdc))>1: continue
      #print origdr,origdc
      dr = origdr
      dc = origdc
      dist = 0
      bound = d/(dr*dr+dc*dc)**.5
      boxr,boxc = initr,initc
      r,c = fr(initr,1),fr(initc,1)
      #r,c = float(initr),float(initc)
      while dist <= bound:
        #print 'at',r,',',c
        #print 'box:',boxr,',',boxc,';',X[boxr][boxc]
        if r==initr and c==initc and dist:
          ans += (dist<=bound)
          break
        k = min((nextpos(r,dr)-r)/dr,(nextpos(c,dc)-c)/dc)
        nextr,nextc = r+k*dr,c+k*dc
        dist += k
        crossr = nextr.denominator==2
        crossc = nextc.denominator==2
        #crossr = nextr%1==.5
        #crossc = nextc%1==.5
        if crossr:
          dboxr = 1 if dr>0 else -1
          if crossc:
            #corner
            dboxc = 1 if dc>0 else -1
            if X[boxr+dboxr][boxc+dboxc] == '#':
              if X[boxr][boxc+dboxc] == '#':
                if X[boxr+dboxr][boxc] == '#':
                  # bounce
                  dist *= 2
                  ans += (dist<=bound)
                  break
                else:
                  # reflect c
                  dc *= -1
                  dboxc = 0
              elif X[boxr+dboxr][boxc] == '#':
                # reflect r
                dr *= -1
                dboxr = 0
              else:
                # suck
                break
            else:
              # go thru
              pass
          else:
            dboxc = 0
            if X[boxr+dboxr][boxc] == '#':
              dr *= -1
              dboxr = 0
        elif crossc:
          dboxr = 0
          dboxc = 1 if dc>0 else -1
          if X[boxr][boxc+dboxc] == '#':
            dc *= -1
            dboxc = 0
        else:
          dboxr=dboxc=0
        r,c = nextr,nextc
        boxr,boxc = boxr+dboxr,boxc+dboxc
      #print origdr,origdc,dist
  return ans

