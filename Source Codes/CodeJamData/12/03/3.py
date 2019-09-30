#!/usr/bin/env python

ri = raw_input

n=int(ri())
for i in xrange(n):
  a,b=map(int,ri().split())
  k=0
  for n in xrange(a,b):
    s = str(n)
    z = set()
    for t in xrange(1,len(s)):
      ss = s[t:]+s[:t]
      if ss[0] != '0' and n<int(ss)<=b:
        z.add(ss)
    k+=len(z)
  print 'Case #%d: %d'%(i+1,k)

