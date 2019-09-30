import psyco
psyco.full()

import sys
import re
import os
import time
from itertools import *
from pprint import pprint

if len(sys.argv) != 2:
    print 'specify input file'
    exit()

startTime = time.clock()

fin = open(sys.argv[1])
fout = open(os.path.splitext(sys.argv[1])[0]+'.out','w')

COLORS = range(256)

def colorArea(c, M):
    return range(max(0, c-M), min(len(COLORS), c+M+1))
    
def naiveSmooth(row, M, I):
    for c in COLORS:
        m = row[c]
        for c2 in COLORS:
            changeCost = ((abs(c2-c)-1)//M+1)*I + row[c2]
            if m > changeCost:
                m = changeCost
        row[c] = m

def solve():
    D, I, M, N = map(int, next(fin).split())
    a = map(int, next(fin).split())
    assert len(a) == N

    cost = [[None]*len(COLORS) for i in range(N+1)]
    for c in COLORS:
        cost[0][c] = 0
        
    for i in range(N):
        for c in COLORS:
            delCost = cost[i][c] + D
            #for c2 in range(max(0, c-M), min(len(COLORS), c+M+1)):
            #    if changeCost > cost[i][c2]:
            #        changeCost = cost[i][c2]
            
            #changeCost = \
            #    abs(a[i] - c) + min([cost[i][c2] for c2 in colorArea(c, M)])
            
            changeCost = abs(a[i] - c) + \
                min(cost[i][max(0, c-M):min(len(COLORS), c+M+1)])
            
            cost[i+1][c] = min(delCost, changeCost)
        # keepCost is covered by changeCost
            
        # handle insertions
        if M > 0:
            naiveSmooth(cost[i+1], M, I)
        
                
    result = min(cost[N][c] for c in COLORS)
    print result
    
    print>>fout, result

numCases = int(next(fin))
for caseNo in range(numCases):
    print '\b'*10,100*caseNo/numCases,'%',
    print>>fout, 'Case #%s:'%(caseNo+1),
    solve()

fin.close()
fout.close()

print '\b'*10+'it took %.1fs'%(time.clock()-startTime)