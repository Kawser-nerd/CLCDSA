#!/usr/bin/python
#use globals

from fractions import gcd

def solve():
    for j in xrange(l,h+1):
        good = True
        for i in L:
            if j%i != 0 and i%j != 0:
                good = False
                break
        if good:
            return j
    return 'NO'


r = input()
for case in range(1,r+1):
    L = map(int,raw_input().split())
    n, l, h = tuple(L) 
    L = map(int,raw_input().split())
    print "Case #%s: %s" % (case, solve())
