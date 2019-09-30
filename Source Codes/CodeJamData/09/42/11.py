import sys
import re
import os
import time
from itertools import *
from pprint import pprint
from collections import deque

if len(sys.argv) != 2:
    print 'specify input file'
    exit()

startTime = time.clock()

fin = open(sys.argv[1])
fout = open(os.path.splitext(sys.argv[1])[0]+'.out','w')

def solve():
    R,C,F = map(int,next(fin).split())
    cave = [list(line.strip()) for line in islice(fin,R)]
    #pprint(cave)
    
    def fall(i,j,h=0):
        #print 'fall',i,j,h
        while i < R-1 and cave[i+1][j] == '.':
            i += 1
            h += 1
        #if i == R-1 or h <= F:
        if h <= F:
            yield (i,j)
        
    def expand(j1,j2,predicate):
        while j1 > 0 and predicate(j1-1):
            j1 -= 1
        while j2 < C and predicate(j2):
            j2 += 1
        return (j1,j2)
        
    def condRange(j,predicate):
        assert predicate(j)
        q = []
        for d in [-1,1]:
            jj = j
            while jj in range(C) and predicate(jj):
                jj += d
            q.append(jj-d)
        result = (q[0],q[1]+1)
        assert result == expand(j,j+1,predicate),"%s %s %s"%(result,expand(j,j+1,predicate),[predicate(j) for j in range(C)])
        return result
    
    def sideSpace(i,j):
        #return condRange(j,lambda j:cave[i][j] == '.')
        return expand(j,j+1,lambda j:cave[i][j] == '.')
    def walkDig(i,j,space):
        floor = condRange(j,lambda j:cave[i+1][j] == '#')
        #space = sideSpace(i,j)
        freeMove = max(floor[0],space[0]),min(floor[1],space[1])
        #print 'floor',floor
        #print 'space',space
        
        if space[0] < floor[0]:
            for x in fall(i,floor[0]-1):
                #print 'fall left',x
                yield (0,x,sideSpace(*x))
        if space[1] > floor[1]:
            for x in fall(i,floor[1]):
                #print 'fall right',x
                yield (0,x,sideSpace(*x))
        if freeMove[1]-freeMove[0] > 1:
            if i < R-2:
                # many dig fall
                for j1 in range(freeMove[0],freeMove[1]):
                    for j2 in range(j1+2,freeMove[1]+1):
                        if (j1,j2) == freeMove:
                            continue
                        for jj in [j1,j2-1]:
                            if cave[i+2][jj] == '#':
                                yield (j2-j1,(i+1,jj),expand(j1,j2,lambda j:cave[i+1][j] == '.'))
                            
            # one dig fall
            for j in range(*freeMove):
                for x in fall(i+1,j,h=1):
                    yield (1,x,sideSpace(*x))
        
    start = list(fall(0,0))
    if len(start) == 0:
        print>>fout,'No'
        return
    start, = start
    if start == R:
        print>>fout,'Yes 0'
        return
    
    start = start+(sideSpace(*start),)
    #print start
    
    best = dict((i,{}) for i in range(R))
    for d,(i,j),s in walkDig(*start):
        best[i][j,s] = d
        
    #pprint(best)
    
    inf = 1e10
    for i in range(R-1):
        for (j,s),curDist in best[i].items():
            for d,(ii,jj),ss in walkDig(i,j,s):
                best[ii][jj,ss] = min(curDist+d,best[ii].get((jj,ss),inf))
            
    #result = min(best.get((R-1,j),inf) for j in range(C))
    
    if len(best[R-1]) > 0:
        print>>fout,"Yes",min(best[R-1].values())
    else:
        print>>fout,"No"

numCases = int(next(fin))
for caseNo in range(numCases):
    print '\b'*10,100*caseNo/numCases,'%',
    print>>fout, 'Case #%s:'%(caseNo+1),
    solve()

fin.close()
fout.close()

print '\b'*10+'it took %.1fs'%(time.clock()-startTime)