#!/usr/bin/python

import sys
from math import *

C = int(sys.stdin.readline())

for testcase in range(C):
    line = sys.stdin.readline().strip().split()
    L = long(line[0])
    P = long(line[1])
    C = long(line[2])

    count = 0

    while(L* C**(2**count) < P):
        count += 1

    print "Case #%d: %d" % (testcase+1,count)
    
    
        
