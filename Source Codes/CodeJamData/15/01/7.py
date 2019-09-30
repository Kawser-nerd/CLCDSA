#!/usr/bin/env python2.7

T = int(raw_input())
for x in xrange(1, T + 1):
    S_max, levels = raw_input().split()
    n = 0
    for k, m in enumerate(map(int, levels)):
        if m > 0 and n < k:
            n = k
        n += m
    print 'Case #{}: {}'.format(x, n - sum(map(int, levels)))
