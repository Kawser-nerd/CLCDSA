#!/usr/bin/python

def solve(N, L, H, inputs):
    for i in xrange(L, H + 1):
        can = True
        for j in inputs:
            if i % j and j % i:
                can = False
        if can:
            return i
    return 'NO'

T = int(raw_input())
for i in range(T):
    N, L, H = [int(s) for s in raw_input().split()]
    inputs = [int(s) for s in raw_input().split()]
    print 'Case #%d: %s' % (i + 1, solve(N, L, H, inputs))
