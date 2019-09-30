#!/usr/bin/python
import sys

def solve(S,Q):
    a = set(S)
    c = 0
    se = S[0]
    for q in Q:
        if q in a:
            a.remove(q)
            if len(a) == 0:
                c += 1
                a = set(S)
                a.remove(q)
        print >> sys.stderr, q, a, c
    return c
        
        
for case in range(input()):
    S = [ raw_input() for i in range(input()) ]
    Q = [ raw_input() for i in range(input()) ]
    
    print "Case #%i: %i" % (case+1, solve(S, Q))
    
    