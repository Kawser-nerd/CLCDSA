# -*- coding: utf-8 -*-

def do(n):
    exists = dict((x, False) for x in xrange(10))
    for x in xrange(len(n) - 1, 0, -1):
        exists[n[x]] = True
        if n[x - 1] < n[x]:
            break
    else:
        return
    for m in xrange(n[x - 1] + 1, 10):
        if exists[m]:
            break
    for p in xrange(x, len(n)):
        if n[p] == m:
            n[p], n[x - 1] = n[x - 1], n[p]
            break
    n[x:] = sorted(n[x:])
    return n

t = int(raw_input())
for _t in xrange(1, t + 1):
    n = [int(x) for x in ('0' * 21 + raw_input())[-22:]]
    k = int(''.join(str(x) for x in do(n)))
    print 'Case #%d: %d' % (_t, k)
