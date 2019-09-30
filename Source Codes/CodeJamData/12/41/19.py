#!/usr/bin/python

import sys

def canswing(N,D,d,l):
  vl = [-1]*N # length of vine usable for swinging
  vl[0]=d[0]

  for i in range(N):
    if (vl[i]==-1):
      continue
    ll=vl[i]
    dd=d[i]
    #print i,ll,dd
    if ((ll+dd)>=D):
      return True
    for j in range(i+1,N):
      if ((ll+dd)>=d[j]):
        nvl=0
        if (l[j]>(d[j]-d[i])):
          nvl=d[j]-d[i]
        else:
          nvl=l[j]
        if (nvl>vl[j]):
          vl[j]=nvl
      else:
          break
  return False

T = int(sys.stdin.readline())
for t in range(T):
  N = int(sys.stdin.readline())

  d = []
  l = []
  for i in range(N):
    toks = sys.stdin.readline().strip().split()
    d.append(int(toks[0]))
    l.append(int(toks[1]))

  D = int(sys.stdin.readline())

  #print N,D,d,l

  if (canswing(N,D,d,l)):
    print "Case #%d: YES" % (t+1)
  else:
    print "Case #%d: NO" % (t+1)

