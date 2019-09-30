#!/usr/bin/python

# c.durr - 2009 . gcj - stock charts
# library from david eppstein - http://www.ics.uci.edu/~eppstein/PADS/

import PartialOrder
def readint():    return int(raw_input())
def readarray(f): return map(f, raw_input().split())

def dom(a,b):
    for i in range(len(a)):
        if a[i]>=b[i]:
            return False
    return True 

def incomp(a,b):
    return not dominates(a,b) and not dominates(b,a)

for test in range(readint()):
    n,k = readarray(int)
    p = [[-1]*k, [1000001]*k]
    for _ in range(n):
        p.append(readarray(int))
    G = {}
    for i in range(len(p)):
        G[i] = []
        for j in range(len(p)):
            if dom(p[i],p[j]):
                G[i].append(j)
    print "Case #%d:"%(test+1), len(PartialOrder.MaximumAntichain(G))

        
    
