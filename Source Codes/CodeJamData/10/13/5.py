import sys
import re
import os
import time
from math import *
from itertools import *
from pprint import pprint

if len(sys.argv) != 2:
    print 'specify input file'
    exit()

startTime = time.clock()

fin = open(sys.argv[1])
fout = open(os.path.splitext(sys.argv[1])[0]+'.out', 'w')

phi = 0.5*(sqrt(5)+1)

def loosing(a, b):
    return a <= b <= int(phi*a) or b <= a <= int(phi*b)

def solve():
    a1, a2, b1, b2 = map(int, next(fin).split())

    n = 0
    for a in range(a1, a2+1):
        for b in range(b1, b2+1):
            if not loosing(a, b):
                n += 1
    print>>fout, n

numCases = int(next(fin))
for caseNo in range(numCases):
    print '\b'*10, 100*caseNo/numCases, '%',
    print>>fout, 'Case #%s:'%(caseNo+1),
    solve()

fin.close()
fout.close()

print '\b'*10+'it took %.1fs'%(time.clock()-startTime)