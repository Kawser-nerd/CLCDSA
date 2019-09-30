z = input()
from collections import *
for cas in xrange(1,z+1):
    n, m = map(int, raw_input().strip().split())
    enters = defaultdict(int)
    leaves = defaultdict(int)
    keys = set()
    normal = 0
    for i in xrange(m):
      o, e, p = map(int, raw_input().strip().split())
      normal += p * (e - o) * (e - o + 1) / 2
      keys.add(o)
      keys.add(e)
      for j in xrange(p):
        enters[o] += 1
        leaves[e] += 1
    stak = []
    for k in sorted(keys):
        for v in xrange(enters[k]):
            stak.append(k)
        for v in xrange(leaves[k]):
            w = stak.pop()
            normal -= (k - w) * (k - w + 1) / 2
    print "Case #%d: %d" % (cas, -normal)
