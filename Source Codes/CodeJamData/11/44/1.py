import sys
import re
import os
import time
from itertools import *
from pprint import pprint
from collections import defaultdict

def solve():
    P, W = map(int, next(fin).split())
    adjanced = defaultdict(set)

    for w in next(fin).split():
        i, j = map(int, w.split(','))
        adjanced[i].add(j)
        adjanced[j].add(i)

    d = {1: 0}
    
    q = [1]
    while q:
        p = q.pop(0)
        for j in adjanced[p]:
            if j not in d:
                d[j] = d[p]+1
                q.append(j)

    print d[0]

    global best_len, best_threatened
    best_len = 1e10
    best_threatened = -1e10

    def threatens(planets):
        result = set()
        for p in planets:
            result |= adjanced[p]
        result = len(result)
        if len(planets) > 1:
            result -= len(planets)
        return result

    path = [0]
    def rec():
        global best_len, best_threatened
        dd = d[path[-1]]-1
        if dd == 0:
            #print path
            threatened = threatens(path)
            if threatened > best_threatened:
                best_threatened = threatened
            return
        for next in adjanced[path[-1]]:
            if d[next] == dd:
                path.append(next)
                rec()
                path.pop()

    rec()

    print>>fout, d[0]-1, best_threatened


if len(sys.argv) != 2:
    print 'specify input file'
    exit()

startTime = time.clock()

fin = open(sys.argv[1])
fout = open(os.path.splitext(sys.argv[1])[0]+'.out', 'w')

numCases = int(next(fin))
for caseNo in range(numCases):
    print '\b'*10, 100*caseNo/numCases, '%',
    print>>fout, 'Case #%s:'%(caseNo+1),
    solve()

try:
    next(fin)
    assert False, 'not all lines are processed'
except StopIteration:
    pass

fin.close()
fout.close()

print '\b'*10+'it took %.1fs'%(time.clock()-startTime)