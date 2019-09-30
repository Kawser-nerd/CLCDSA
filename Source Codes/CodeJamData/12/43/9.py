#! /usr/bin/env python

from sys import stdin
import numpy as np

ntest = input()

for test in range(ntest):
    n = input()
    x = np.array([int(i)-1 for i in stdin.readline().strip().split()])
    
    y = np.zeros(n, np.int)
    fixed = np.zeros(n, np.bool)
    
    possible = True
    for i in xrange(n-1):
        fixed[x[i]] = True
        if True in fixed[i+1:x[i]]:
            possible = False
            break
        for j in xrange(i+1, x[i]):
            y[j] = y[j] - x[i] + j
    
    y = y - y.min()
    result = ' '.join(['%d' % i for i in y]) if possible else 'Impossible'
    print "Case #%d: %s" % (test+1, result)