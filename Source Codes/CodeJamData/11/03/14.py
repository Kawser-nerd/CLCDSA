#!/usr/bin/env python

import sys

def c():
 t = int(sys.stdin.readline())
 for ix in xrange(t):
     n = int(sys.stdin.readline())
     numbers = map(int, sys.stdin.readline().strip().split())
     x = reduce(lambda acc,x: acc ^ x, numbers, 0)
     if x != 0:
         print "Case #%d: NO" % (ix + 1)
     else:
         print "Case #%d: %d" % (ix + 1, sum(numbers) - min(numbers))

c()
