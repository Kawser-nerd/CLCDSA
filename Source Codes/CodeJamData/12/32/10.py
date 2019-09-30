#!/usr/bin/python

import sys
import re
import math
import fractions
#import numpy

f = open(sys.argv[1],'r')
num = int(f.readline())
for z in range(num):
    d,n,m = f.readline().split()
    d = float(d)
    n = int(n)
    m = int(m)
    tx = []
    for i in range(n):
        tx.append([float(x) for x in  f.readline().split()])
    tx.sort()
    a = [float(x) for x in  f.readline().split()]
    #print tx
    if len(tx) > 1:
        tf = tx[0][0] + (d - tx[0][1]) * (tx[1][0] - tx[0][0]) / (tx[1][1] - tx[0][1])
    else:
        tf = 0
    #print tf
    #print d,n,m,tx,a
    print 'Case #{}:'.format(z+1)
    for x in a:
        print max(math.sqrt(2*d/x), tf)
    sys.stdout.flush()
