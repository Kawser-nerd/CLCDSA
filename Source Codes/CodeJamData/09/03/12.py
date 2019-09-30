table = {}
def count(s, t='welcome to code jam'):
  if not t: return 1
  k = s,t
  if k in table: return table[k]
  r = 0
  for i in xrange(len(s)):
    if s[i] == t[0]: r += count(s[i+1:], t[1:])
  r = r % 10000
  table[k] = r
  return r
        
import sys
N = int(sys.stdin.readline())
for i in xrange(N):
  print 'Case #%d: %04d' % (i+1, count(sys.stdin.readline().strip()))
