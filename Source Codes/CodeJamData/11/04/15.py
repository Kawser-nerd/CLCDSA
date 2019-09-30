#!/usr/bin/env python

import sys

def c():
    t = int(sys.stdin.readline())
    for i in xrange(t):
        n = int(sys.stdin.readline())
        arr = map(int, sys.stdin.readline().strip().split())
        arr = [x - 1 for x in arr]
        assert len(arr) == n
        count = 0
        seen = [False for _ in xrange(n)]
        for ix,x in enumerate(arr):
            if x == ix:
                continue
            while not seen[x]:
                seen[x] = True
                x = arr[x]
                count += 1
        print "Case #%d: %d" % (i+1, count)

c()
