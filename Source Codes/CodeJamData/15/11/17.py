#!/usr/bin/env python

T = int(raw_input())

for z in xrange(1,T+1):
    N = int(raw_input())
    l = map(int, raw_input().split())

    a = 0
    rate = 0
    for i in xrange(N-1):
        if l[i+1] < l[i]:
            a += l[i] - l[i+1]
            rate = max(rate, l[i] - l[i+1])

    b = 0
    for i in xrange(N-1):
        b += min(rate, l[i])

    print "Case #%d: %d %d" % (z, a, b)
