#!/usr/bin/python

import sys
from collections import defaultdict

mod = 10007

cases = int(sys.stdin.readline())
for case in xrange(1, cases+1):
    h, w, r = [int(x) for x in sys.stdin.readline().split()]
    bad = set()
    for _ in xrange(r):
        i, j = [int(x) for x in sys.stdin.readline().split()]
        bad.add((i, j))
    tab = defaultdict(int)
    tab[h, w] = 1
    for i in xrange(h, 0, -1):
        for j in xrange(w, 0, -1):
            if (i, j) in bad:
                continue
            if (i, j) == (h, w):
                continue
            tab[i,j] = (tab[i+2,j+1] + tab[i+1,j+2]) % mod
    print 'Case #%d: %d' % (case, tab[1,1] % mod)
