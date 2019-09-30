#!/usr/bin/python

# google code jam - c.durr - 2011

# Revenge of the Hot Dogs
# maximisation

try:
    import psyco
except:
    pass

from math      import *
from fractions import *

def readint():    return int(raw_input())
def readarray(f): return map(f, raw_input().split())


def time(D, s):
    tot = sum([x[1] for x in s])
    dis = s[-1][0] - s[0][0]
    return (D*(tot-1)-dis)/2.0
    
for test in range(readint()):
    C,D = readarray(int)
    tab = []
    for i in range(C):
        tab.append(readarray(int))
    tab.sort()
    
    t = max([time(D, tab[a:(b+1)]) for a in range(C) for b in range(a,C)])
    
    
    print "Case #%i:"% (test+1), t
    
    
    
