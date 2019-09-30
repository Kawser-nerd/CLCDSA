import sys
import re
import os
import time
from itertools import *
from pprint import pprint
from collections import defaultdict


def solve():
    X, S, R, t, N = map(int, next(fin).split())

    intervals = defaultdict(int)

    prev = 0
    for _ in range(N):
        b, e, w = map(int, next(fin).split())
        intervals[S] += b-prev
        intervals[S+w] += e-b
        prev = e
    intervals[S] += X-prev
    #pprint(dict(intervals))
    assert sum(intervals.values()) == X


    time = 0
    for v, d in sorted(intervals.items()):
        V = v+R-S
        q = min(1.0*d/V, t)
        t -= q
        time += 1.0*d/v - 1.0*q*(V-v)/v
        

    print>>fout, time


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