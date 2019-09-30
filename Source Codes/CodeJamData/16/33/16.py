#!/usr/bin/env python

for nnn in xrange(1, int(raw_input())+1):
  print "Case #%d:" % (nnn),
  J, P, S, K = [int(x) for x in raw_input().split()]

  print min(J*P*S, J*P*K)
  for j in xrange(J):
    for p in xrange(P):
      for s in xrange(j+p, min(j+p+K, j+p+S)):
        print j+1, p+1, (s%S)+1

