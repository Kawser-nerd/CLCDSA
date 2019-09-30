#!/usr/bin/env python

import sys
import math

def gcd(a,b):
    while b:
        a, b = b, a % b
    return a

def gcd_l(l):
    return reduce(gcd, l)

C = int(sys.stdin.readline())
for i in xrange(C):
    l = [int(x) for x in sys.stdin.readline().split()][1:]
    l.sort()
    l.reverse()
    now = l[0]
    g = [now - x for x in l]
    T = gcd_l(g)
    print "Case #" + str(i+1) + ": " + str(((now-1)/T + 1)*T-now)
    
        


