#!/usr/bin/env python

for nnn in xrange(1, int(raw_input())+1):
  print "Case #%d:" % (nnn),
  B, M = [int(x) for x in raw_input().split()]
  if M > 2**(B-2):
    print 'IMPOSSIBLE'
  else:
    print 'POSSIBLE'
    num = bin(M)[2:].zfill(B-1)
    if num[0] == '1':
      print '0' + '1'*(B-1)
    else:
      print '0' + num[1:] + '0'
    for i in xrange(1, B):
      print '0'*(i+1) + '1'*(B-i-1)

