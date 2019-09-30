import sys
import re
import os
import time
import string
from copy import copy
from itertools import *
from pprint import pprint

if len(sys.argv) != 2:
    print 'specify input file'
    exit()

startTime = time.clock()

fin = open(sys.argv[1])
fout = open(os.path.splitext(sys.argv[1])[0]+'.out','w')

def paths(n,i,j,W):
    if n == 1:
        yield [(i,j)]
        return
    for p in paths(n-1,i,j,W):
        i,j = p[-1]
        for di,dj in [(1,0),(0,1),(-1,0),(0,-1)]:
            if i+di >= 0 and i+di < W and j+dj >= 0 and j+dj < W:
                yield p+[(i+di,j+dj)]

def solve():
    W,Q = map(int,next(fin).split())
    square = map(string.strip,islice(fin,W))
    queries = map(int,next(fin).split())
    assert len(queries) == Q
    deltas = {}
    deltasFrom = {}
    for i in range(W):
        for j in range(W):
            deltas[i,j] = []
    for i in range(W):
        for j in range(W):
            if not square[i][j].isdigit():
                continue
            for p in paths(3,i,j,W):
                assert len(p) == 3
                s = ''.join(square[ii][jj] for ii,jj in p)
                assert re.match(r'^\d[-+]\d$',s),s
                deltas[i,j].append((p[-1],s[1:]))
                #deltasFrom[p[-1]].append(((i,j),s[1:]))
    sols = {}
    new = {}
    def goto(value,coords,sol):
        old = sols.get((value,coords))
        if old is None:
            sols[value,coords] = sol
            new[value,coords] = sol
            return
        #if len(sol) < len(old):
        assert len(sol) >= len(old)
        if len(sol) == len(old) and sol < old:
            assert (value,coords) in new
            sols[value,coords] = sol
            new[value,coords] = sol
    
    for i in range(W):
        for j in range(W):
            if square[i][j].isdigit():
                v = int(square[i][j])
                new[v,(i,j)] = str(v)
                sols[v,(i,j)] = str(v)
    
    while True:
        #print '.'
        #pprint(new)
        cur = copy(new)
        new = {}
        for (value,coords),sol in cur.items():
            for newCoords,d in deltas[coords]:
                goto(value+int(d),newCoords,sol+d)
        found = set(v for v,_ in sols)
        if all(q in found for q in queries):
            break
    bestSols = {}
    for (v,coords),sol in sols.items():
        x = bestSols.get(v)
        if x is None or len(x)>len(sol) or len(x)==len(sol) and x>sol:
            bestSols[v] = sol
    for q in queries:
        print>>fout,bestSols[q]

numCases = int(next(fin))
for caseNo in range(numCases):
    print '\b'*10,100*caseNo/numCases,'%',
    print>>fout, 'Case #%s:'%(caseNo+1)
    solve()

fin.close()
fout.close()

print '\b'*10+'it took %.1fs'%(time.clock()-startTime)