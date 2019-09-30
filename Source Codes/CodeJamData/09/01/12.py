import sys,re
f = sys.stdin
L,D,N = map(int,f.readline().split())
words = [f.readline().strip() for i in xrange(D)]
tests = [f.readline().strip() for i in xrange(N)]
tests = map(lambda x:('^'+x.replace('(','[').replace(')',']')+'$'), tests)
for i,v in enumerate(tests):
  print 'Case #%d: %d' % (i+1, len(filter(None,(re.match(v, w) for w in words))))


