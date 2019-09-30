#!/usr/bin/python

# google code jam - c.durr - 2009

#
#

import sys

T = int(raw_input())
for t in range(T):
    c = raw_input()
    d = {c[0]:1}
    b = max(2, len(dict([ (x, 0) for x in c])))
    n = 0
    r = 0
    for x in c:
        if not x in d:
            while n in d.values():
                n = n + 1
            d[x] = n
            n = n + 1
        r = b*r + d[x]    
     
    print "Case #%i:"% (t+1), r    
    
