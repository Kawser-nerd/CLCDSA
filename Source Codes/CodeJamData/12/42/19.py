#!/usr/bin/python

import sys,random

def biggeststudentleft(N,R,s):
  br=0
  bi=-1;
  for i in range(N):
    if not s[i]:
      if (R[i]>br):
        br=R[i]
        bi=i
  return bi

def distsq(a,b):
  dx=a[0]-b[0]
  dy=a[1]-b[1]
  return dx*dx+dy*dy

def isvalidplacement(N,R,p,s,i,xy):
  r=R[i]
  for j in range(N):
    if (s[j]):
      dd=distsq(p[j],xy)
      r=R[i]+R[j]
      if (dd<(r*r)):
        return False
  return True

def placestudent(N,W,L,R,p,s):
  bi=biggeststudentleft(N,R,s)
  #print bi

  corners=[[0,0],[0,L],[W,0],[W,L]]
  random.shuffle(corners)
  for xy in corners:
    if (isvalidplacement(N,R,p,s,bi,xy)):
      p[bi]=xy
      s[bi]=True
      return True

  for i in range(100):
    x=random.random()*W
    y=random.random()*L
    if (isvalidplacement(N,R,p,s,bi,[x,y])):
      p[bi]=[x,y]
      s[bi]=True
      return True


  #s[bi]=True
  return False


T = int(sys.stdin.readline())
for t in range(T):
  toks = sys.stdin.readline().strip().split()
  N = int(toks[0])
  W = int(toks[1])
  L = int(toks[2])

  R=[]
  toks = sys.stdin.readline().strip().split()
  for i in range(N):
    R.append(int(toks[i]))

  #print N,W,L,R

  foundplacement=False
  while (not foundplacement):
    p=[[0,0]]*N
    s=[False]*N;
    cannotplace=False
    for i in range(N):
      if not placestudent(N,W,L,R,p,s):
        cannotplace=True
        break

    if (cannotplace):
      #print "Failed",
      #break
      continue
    #print p

    print "Case #%d:" % (t+1),
    for i in range(N):
      print "%f %f" %(p[i][0],p[i][1]),
    print
    foundplacement=True

