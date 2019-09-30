#!/usr/bin/python

# Run by:
#     cat input | a.py

import sys
from math import sqrt

l = sys.stdin.readline()
n = int(l)

for i in range(n):
    print 'Case #%d:' % (i+1,),

    l = sys.stdin.readline()
    n_engines = int(l)
    engines = []
    for j in range(n_engines):
        l = sys.stdin.readline()
        engines.append(l.strip())
        
    l = sys.stdin.readline()
    n_searches = int(l)
    remaining = engines[:]
    switches = 0
    for j in range(n_searches):
        l = sys.stdin.readline()
        search = l.strip()
        if search in remaining:
            remaining.remove(search)
            if not remaining:
                switches += 1
                remaining = engines[:]
                remaining.remove(search)
    print switches
    
