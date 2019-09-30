#!/usr/bin/env python

ri = raw_input

t = int(ri())
for case in xrange(1,t+1):
  foo = map(int,ri().split())
  n,s,p = foo[:3]
  base=0
  depends=0
  for score in foo[3:]:
    if score == 0:
      if p==0:
        base += 1
    elif score%3==0:
      if score/3>=p: 
        base += 1
      elif score/3==p-1:
        depends += 1
    elif score%3==1:
      if score/3+1>=p:
        base += 1
    else:
      if score/3+1>=p:
        base += 1
      elif score/3+1==p-1:
        depends += 1
  ans = base + min(depends,s)
  print 'Case #%d:'%case,ans

