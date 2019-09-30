import sys
import re
import os
import time
from itertools import *
from pprint import pprint
from copy import deepcopy


def accumulate(m):
    h = len(m)
    w = len(m[0])
    #result = [[0]*(w+1) for _ in range(h+1)]
    result = [[0]*(w+1)] + [[0]+row for row in m]
    for i in range(h+1):
        for j in range(w):
            result[i][j+1] += result[i][j]
    for j in range(w+1):
        for i in range(h):
            result[i+1][j] += result[i][j]
    return result


def bias(m, vx, vy):
    h = len(m)
    w = len(m[0])
    result = deepcopy(m)
    for i in range(h):
        for j in range(w):
            result[i][j] *= vx*j+vy*i
    return result


def rect(m, i1, j1, i2, j2):
    return m[i2][j2]+m[i1][j1]-m[i1][j2]-m[i2][j1]


def blade(m, a, i, j, k):
    return rect(a, i, j, i+k, j+k) - m[i][j]-m[i][j+k-1]-m[i+k-1][j]-m[i+k-1][j+k-1]


def solve():
    R, C, D = map(int, next(fin).split())

    weights = []
    for _ in range(R):
        weights.append(map(int, next(fin).strip()))

    for row in weights:
        for j in range(len(row)):
            row[j] += D

    #pprint(accumulate(weights))
    wx = bias(weights, 1, 0)
    wy = bias(weights, 0, 1)
    s = accumulate(weights)
    sx = accumulate(wx)
    sy = accumulate(wy)

    def is_centered(i, j, k):
        q = blade(weights, s, i, j, k)
        qx = blade(wx, sx, i, j, k)
        #print 1.0*qx/q
        if 2*qx != q*(2*j+k-1):
            return False
        qy = blade(wy, sy, i, j, k)
        if 2*qy != q*(2*i+k-1):
            return False

        return True

    for k in range(min(R, C), 2, -1):
        for i in range(R-k+1):
            for j in range(C-k+1):
                if is_centered(i, j, k):
                    print>>fout, k
                    return

    print>>fout, "IMPOSSIBLE"


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