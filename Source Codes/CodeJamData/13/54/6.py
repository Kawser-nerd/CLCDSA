from sys import stdin

def getans(conf):
  if conf in cost: return cost[conf]
  ret = 0.0
  for i in xrange(len(conf)):
    j = 0
    while conf[(i+j)%N] == 'X': j += 1
    p = (i+j)%N
    ret += 1.0 / len(conf) * ((len(conf) - j) + getans(conf[:p]+'X'+conf[p+1:]))
  cost[conf] = ret
  #print conf, ret
  return ret

T = int(stdin.readline())
for _ in xrange(1, T+1):
  conf = stdin.readline()[:-1]
  mask = 0
  for x in conf:
  N = len(conf)
  cost = {'X'*len(conf) : 0}
  print 'Case #%d: %.14f' % (_, getans(conf))
