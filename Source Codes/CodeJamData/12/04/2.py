#!/usr/bin/env python

import d

ri = raw_input
t = int(ri())
for case in xrange(1,t+1):
  h,w,ddd = map(int,ri().split())
  X = list()
  for i in xrange(h):
    line = ri()
    X.append(line)
  print 'Case #%d: %d'%(case,d.blah(ddd,X))

