#!/usr/bin/python

# google code jam - c.durr - 2012

#
#

try:
    import psyco
except:
    pass

from math import *
from fractions import *
from heapq import *

def readint():    return int(raw_input())
def readarray(f): return map(f, raw_input().split())

def solve():
    '''dijkstra'''
    dist = [[ [] for j in range(M)] for i in range(N)]
    Q = []
    heappush(Q, (0,0,0))
    while dist[N-1][M-1]==[]:
        t,i,j = heappop(Q)
        if dist[i][j]!=[]:
            continue
        dist[i][j] = t
        # construct neighbor list
        for (i1,j1) in [(i-1,j),(i+1,j),(i,j-1),(i,j+1)]: 
            if i1<0 or i1>=N or j1<0 or j1>=M:
                continue
            if top[i1][j1]-bot[i1][j1]<50:
                continue
            if top[i][j]-bot[i1][j1]<50:
                continue
            if top[i1][j1]-bot[i][j]<50:
                continue
            d1 = max(0, H-t-(top[i1][j1]-50))
            d2 = 10 if H-t-d1-bot[i][j]>=20 else 100
            t1 = t+d1+d2 if t+d1>0 else 0
            if dist[i1][j1]>t1:
                heappush(Q, (t1,i1,j1))
    return dist[N-1][M-1]*0.1
                    
for test in range(readint()):
    H,N,M = readarray(int)
    top = []
    for _ in range(N):
        top.append(readarray(int))
    bot = []
    for _ in range(N):
        bot.append(readarray(int))
    print "Case #%i:"% (test+1), solve()
    
    
