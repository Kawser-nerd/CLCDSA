#!/usr/bin/python

# google code jam - c.durr - 2011

# RIP
# ad hoc, linear time

try:
    import psyco
except:
    pass

from math      import *
from fractions import *

def readint():    return int(raw_input())
def readarray(f): return map(f, raw_input().split())

def average(tab):
    return sum(tab)/len(tab)

for test in range(readint()):
    N = readint()
    opp = [[] for _ in range(N)]
    wp_n = [0]*N
    G = {}
    for i in range(N):
        l = raw_input()
        for j in range(N):
            if l[j]!='.':
                opp[i].append(j)
                G[i,j] = int(l[j])
                wp_n[i] += int(l[j])
    wp = [Fraction(wp_n[i],len(opp[i])) for i in range(N)]
    owp = []
    for i in range(N):
        owp.append(average([Fraction(wp_n[j]-G[j,i],len(opp[j])-1) for j in opp[i]]))
    oowp = []
    for i in range(N):
        oowp.append(average([owp[j] for j in opp[i]]))
    
    print "Case #%i:"% (test+1)
    for i  in range(N):
        print float(average([wp[i],owp[i],owp[i],oowp[i]]))
    
    
    
