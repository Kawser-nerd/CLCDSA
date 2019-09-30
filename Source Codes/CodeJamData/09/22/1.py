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

def nextPerm(x):
    n = len(x)
    assert list(reversed(x)) != list(sorted(x))
    for i in reversed(range(n-1)):
        if x[i] < x[i+1]:
            break
    tail = x[i+1:]
    q = min(t for t in tail if t > x[i])
    j = tail.index(q)
    x[i],tail[j] = tail[j],x[i]
    x[i+1:] = sorted(tail)
    
def solve():
    n = next(fin).strip()
    n = '0'+n
    n = list(n)
    nextPerm(n)
    while len(n) > 1 and n[0] == '0':
        n = n[1:]
    print>>fout,''.join(n)
    

numCases = int(next(fin))
for caseNo in range(numCases):
    print '\b'*10,100*caseNo/numCases,'%',
    print>>fout, 'Case #%s:'%(caseNo+1),
    solve()

fin.close()
fout.close()

print '\b'*10+'it took %.1fs'%(time.clock()-startTime)