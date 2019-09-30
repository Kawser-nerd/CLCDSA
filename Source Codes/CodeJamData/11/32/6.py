#!/usr/bin/python

from heapq import nlargest

def solve(inputs):
    L, t, N, C = inputs[0:4]
    cycle = inputs[4:]
    dists = []
    for i in xrange(N):
        dists.append(cycle[i % C])
    tmp = 0
    rest = 0
    for i in xrange(N):
        tmp += dists[i]
        if tmp > t * 0.5:
            start = i
            rest = tmp - t * 0.5
            break
    result = sum(dists) * 2
    dists = [rest] + dists[i + 1:]
    for x in nlargest(L, dists):
        result -= x
    return result

T = int(raw_input())
for i in range(T):
    inputs = [int(s) for s in raw_input().split()]
    print 'Case #%d: %d' % (i + 1, solve(inputs))
