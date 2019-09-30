#!/usr/bin/python

# c.durr - 2009 . gcj - stock charts
# library from david eppstein - http://www.ics.uci.edu/~eppstein/PADS/

import PartialOrder
def readint():    return int(raw_input())
def readarray(f): return map(f, raw_input().split())

for test in range(readint()):
    N = readint()
    t = []
    for _ in range(N):
        s = raw_input()
        idx = -1
        for i in range(len(s)):
            if s[i]=='1':
                idx = i
        t.append(idx)

    cost = 0
    for i in range(N):
        for j in range(i,N):
            if t[j]<=i:
                cost += j-i
                for k in range(j,i,-1):
                    t[k] = t[k-1]
                break
    print "Case #%d:"%(test+1), cost

