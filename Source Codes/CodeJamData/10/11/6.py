import sys
import re
import os
import time
from itertools import *
from pprint import pprint
import string

if len(sys.argv) != 2:
    print 'specify input file'
    exit()

startTime = time.clock()

fin = open(sys.argv[1])
fout = open(os.path.splitext(sys.argv[1])[0]+'.out', 'w')


def solve():
    N, K = map(int, next(fin).split())
    board = map(string.strip, islice(fin, N))
    assert len(board) == N
    assert all(len(row) == N for row in board)

    def maxConsequent(c, xs):
        m = 0
        t = 0
        for x in xs:
            if x == c:
                t += 1
                m = max(t, m)
                #if m >= K:
                #    break
            else:
                t = 0
        return m

    def maxHorLen(c, board):
        return max(maxConsequent(c, row) for row in board)

    def maxDiagLen(c, board):
        m = 0
        for i,j in [(i, 0) for i in range(N)]+[(0, j) for j in range(1, N)]:
            diag = [board[i+k][j+k] for k in range(N-max(i, j))]
            mc = maxConsequent(c, diag)
            #print diag, mc
            m = max(mc, m)
        return m
    
    def maxRowLen(c, board):
        m = max(maxHorLen(c, board), maxDiagLen(c, board))
        board = list(reversed(zip(*board)))
        #pprint(board)
        m = max(maxHorLen(c, board), maxDiagLen(c, board), m)
        return m
        
    assert maxRowLen('R', board) < K
    assert maxRowLen('B', board) < K

    # gravity
    for i in range(N):
        board[i] = sorted(board[i],key=lambda c: c != '.')
        
    #pprint(board)
        
    r = maxRowLen('R', board)
    b = maxRowLen('B', board)
    
    print r, b
    
    if r >= K:
        if b >= K:
            print>>fout, "Both"
        else:
            print>>fout, "Red"
    else:
        if b >= K:
            print>>fout, "Blue"
        else:
            print>>fout, "Neither"


numCases = int(next(fin))
for caseNo in range(numCases):
    print '\b'*10, 100*caseNo/numCases, '%',
    print>>fout, 'Case #%s:'%(caseNo+1),
    solve()

fin.close()
fout.close()

print '\b'*10+'it took %.1fs'%(time.clock()-startTime)

