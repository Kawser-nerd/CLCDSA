#!/usr/bin/env python

A = [chr(ord('A')+i) for i in xrange(26)]
for nnn in xrange(1, int(raw_input())+1):
  print "Case #%d:" % (nnn),
  N = int(raw_input())
  P = [int(x) for x in raw_input().split()]
  S = sorted(zip(P, A), reverse=True)
  if S[0][0] > S[1][0]:
    print ' '.join([S[0][1]] * (S[0][0]-S[1][0])),
  for i in xrange(2, len(S)):
    print ' '.join([S[i][1]] * S[i][0]),
  print ' '.join([S[0][1]+S[1][1]] * S[1][0])

