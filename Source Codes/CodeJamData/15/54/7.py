#!/usr/bin/python

import math, collections, itertools
import sys

NCASE = int(sys.stdin.readline())


for case in range(1,NCASE+1):
    P = map(int, sys.stdin.readline().split())[0]
    E = map(int, sys.stdin.readline().split())
    F = map(int, sys.stdin.readline().split())

    count = dict( (e,f) for (e,f) in zip(E,F) )
    ans = []

    if count[0] > 1:
        while count[0] > 1:
            ans.append(0)
            count[0] /= 2
        m = 1 << len(ans)
        for k in count:
            if k != 0:
                count[k] /= m

    keys = sorted(count.keys())
    while len(keys) > 1:
        key = keys[1]   # keys[0] = 0
        ans.append(key)
        nc = {}
        nkeys = []
        for k in reversed(keys):
            if count[k] > 0:
                count[k-key] -= count[k]
                nc[k-key] = count[k]
        count = nc
        keys = sorted(nc.keys())

    ans = ' '.join(map(str,sorted(ans)))

    print 'Case #%d: %s' % (case, ans)

