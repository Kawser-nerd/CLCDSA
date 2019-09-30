#!/usr/bin/env python

def sumsqr(n, base):
    res = 0
    while n > 0:
        k = n % base
        n = (n-k)/base
        res += k*k
    return res

def find(bases):
    least = 1
    ok = False
    happy = dict( [(b, {1:True}) for b in bases] )
    while not ok:
        least += 1
        ok = True
        for b in bases:
            seen = {}
            k = least
            while k not in seen and k not in happy[b]:
                seen[k] = True
                k = sumsqr(k, b)
            if k in happy[b]:
                happy[b].update(seen)
            else:
                ok = False
                break
    return least

import sys
f = sys.stdin
cases = int(f.readline().strip())
for c in xrange(cases):
    bases = map(int, f.readline().strip().split())
    print "Case #%d: %d" % (c+1, find(bases))

