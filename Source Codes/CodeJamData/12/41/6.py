#! /usr/bin/env python

from sys import stdin
import numpy as np

ntest = input()

for test in range(ntest):
    n = input()
    d = np.zeros(n, np.int)
    l = np.zeros(n, np.int)
    maxlen = np.zeros(n, np.int)
    
    for i in range(n):
        line = stdin.readline().strip().split()
        d[i], l[i] = int(line[0]), int(line[1])

    D = input()
    
    success = False
    maxlen[0] = d[0]
    
    for i in xrange(n):
        maxlen[i] = min(l[i], maxlen[i])
        if maxlen[i] >= D - d[i]:
            success = True
            break
        j = i+1
        while (j<n) and (maxlen[i] >= d[j] - d[i]):
            maxlen[j] = max(maxlen[j], d[j] - d[i])
            j = j+1
    print "Case #%d: %s" % (test+1, "YES" if success else "NO")