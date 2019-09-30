#!/usr/bin/env python2.7

table = [[]]
for i in xrange(1, 1001):
    table.append([(j - 1) / i for j in xrange(1001)])

T = int(raw_input())
for x in xrange(1, T + 1):
    D = int(raw_input())
    P = map(int, raw_input().split())
    counts = [0] * 1001
    for p in P:
        counts[p] += 1
    m = max(P)
    y = m
    for i in xrange(1, m + 1):
        y = min(y, i + sum(table[i][j] * counts[j] for j in xrange(i + 1, m + 1)))
    print 'Case #{}: {}'.format(x, y)
