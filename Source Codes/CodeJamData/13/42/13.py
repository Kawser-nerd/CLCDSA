#!/usr/bin/python

import sys
import re
import math
import string

f = open(sys.argv[1],'r')
num = int(f.readline())

for i in xrange(num):
    l = f.readline()
    N, P = [int(x) for x in l.split()]
    #print N,P
    if 2**N == P:
        print 'Case #{}:'.format(i+1), 2**N - 1, 2**N - 1
        continue
    j = 0
    while P >= 2**j:
        j += 1
    j -= 1
    k = 1
    while P > 2**N - 2**(N-k):
        k += 1
    #print j, k
    print 'Case #{}:'.format(i+1), 2**k - 2, 2**N - 2**(N-j)
