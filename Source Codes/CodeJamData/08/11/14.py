#!/usr/bin/env python

import sys

argv = sys.argv[1:]

testFile = open(argv[0] + '.in', 'rb')
outFile = open(argv[0] + '.out', 'wb')
nCases = int(testFile.readline())

for i in xrange(1, nCases+1):
    n = int(testFile.readline())
    v1 = sorted(int(val) for val in testFile.readline().split())
    v2 = sorted(int(val) for val in testFile.readline().split())
    
    v2 = v2[::-1]
    
    outFile.write('Case #%i: %i\n' % (i, sum(a*b for a,b in zip(v1,v2))))