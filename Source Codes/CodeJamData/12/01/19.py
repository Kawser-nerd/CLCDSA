import sys

a='ejp mysljylc kd kxveddknmc re jsicpdrysi'\
  'rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd'\
  'de kr kd eoya kw aej tysr re ujdr lkgc jv'

b='our language is impossible to understand'\
  'there are twenty six factorial possibilities'\
  'so it is okay if you want to just give up'

h = {}
for i in range(len(a)):
  h[a[i]]=b[i]
h['q']='z'
h['z']='q'


for case_index in range(1, 1+input()):

  sys.stderr.write(str(case_index)+' ')
  res=''.join(map(h.__getitem__,raw_input()))
  print 'Case #%s: %s'%(case_index,res)

sys.stderr.write('\n')

