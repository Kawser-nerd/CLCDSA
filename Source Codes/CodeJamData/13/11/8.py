#!/usr/bin/env python3

tn = int(input())
for t in range(1, tn + 1):
    r, v = map(int, input().split())
    mn, mx = 0, v
    while mn < mx:
        av = (mn + mx + 1) // 2
        tt = 2 * av * (r + av) - av
        if tt > v:
          mx = av - 1
        else:
          mn = av
    print("Case #%d: %d" % (t, mn))

