#!/usr/bin/env python
import sys

fin = iter(sys.stdin)
T = int(next(fin))
for t in xrange(T):
    N = int(next(fin))

    perm = map(int, next(fin).split())

    cnt = 0
    for i, x in enumerate(perm):
        if i > x:
            cnt += 1
    #print 'Case #%d: %d' % (t+1, cnt)
    if cnt < 487:
        print 'Case #%d: BAD' % (t+1)
    else:
        print 'Case #%d: GOOD' % (t+1)
