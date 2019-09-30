#!/usr/bin/env python

foo = """ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv
our language is impossible to understand
there are twenty six factorial possibilities
so it is okay if you want to just give up""".split('\n')
bar = ' '.join(foo[:3])
baz = ' '.join(foo[3:])
m = {}
for x,y in zip(bar,baz):
  m[x]=y
m['q'] = 'z'
m['z'] = 'q'
ri = raw_input
t = int(ri())
for i in xrange(t):
  inp = ri()
  out = ''
  for l in inp:
    out += m[l]
  print 'Case #%d:'%(i+1),out
