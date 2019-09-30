def sum(x, base):
  r = 0
  while x:
    r += (x % base)**2
    x /= base
  return r

_happy = {}
def happy(x, base):
  if x == 1: return 1
  if (x,base) in _happy:
    return _happy[(x,base)]
  _happy[(x,base)] = 0
  r = happy(sum(x,base), base)
  _happy[(x,base)] = r
  return r
import sys
T = int(sys.stdin.readline())
for i in xrange(T):
  bases = map(int,sys.stdin.readline().split())
  x = 1
  while 1:
    x += 1
    h = True
    for b in bases:
      if not happy(x, b): 
        h = False
        break
    if h:
      print 'Case #%d: %d' % (i+1, x)
      break
    


