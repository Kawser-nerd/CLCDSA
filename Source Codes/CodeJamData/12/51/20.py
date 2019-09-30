#!/usr/bin/python

import sys

T = int(sys.stdin.readline())
for t in range(T):
  N = int(sys.stdin.readline())

  toks = sys.stdin.readline().strip().split()
  L = []
  for tok in toks:
    L.append(float(tok))

  toks = sys.stdin.readline().strip().split()
  P = []
  for tok in toks:
    P.append(float(tok)/100)

  #print
  #print N,L,P

  E = []
  for i in range(N):
    e = 1.0/(1-P[i])
    E.append(e)
  #print "E:",E

  X = []
  for i in range(N):
    x=L[i]*E[i]
    if E[i]==1:
      x=0
    X.append([x,-i])

  #print "X:",X
  X.sort(reverse=True)
  #print "X:",X

  print "Case #%d:" % (t+1),
  for x in X:
    print (-x[1]),
  print

