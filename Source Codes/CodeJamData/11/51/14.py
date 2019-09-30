from __future__ import division
import sys
import re
import os
import time
from itertools import *
from pprint import pprint
from copy import copy
import multiprocessing
from cStringIO import StringIO
from collections import defaultdict

mp = True

###################################

def func_bisect(f, x, lo, hi, eps=1e-9):
    while lo+eps < hi:
        mid = (lo+hi)*0.5
        if x < f(mid): hi = mid
        else: lo = mid
    return lo


def solve(fin, fout, only_read=False):
    W, L, U, G = map(int, next(fin).split())

    incline = defaultdict(float)

    lower = []
    for _ in range(L):
        lower.append(map(int, next(fin).split()))
    upper = []
    for _ in range(U):
        upper.append(map(int, next(fin).split()))

    if only_read:
        return

    h0 = upper[0][1]-lower[0][1]

    for s, side in (-1, lower), (1, upper):
        for (x, y), (next_x, next_y) in zip(side, side[1:]):
            incline[x] += s*(next_y-y)/(next_x-x)

    incline = [(k, incline[k]) for k in sorted(incline)]
    #print incline

    def area(points):
        s = 0
        for i in range(len(points)):
            x, y = points[i]
            x1, y1 = points[(i+1)%len(points)]
            s += (x+x1)*(y-y1)
        assert s >= 0
        return s*0.5

    def part(polyline, x1, x2):
        #print polyline, x1, x2
        result = []
        for i in range(len(polyline)-1):
            x, y = polyline[i]
            next_x, next_y = polyline[i+1]
            if next_x < x1:
                continue
            if x > x2:
                break
            if x < x1:
                result.append((x1, y+(next_y-y)*(x1-x)/(next_x-x)))
            else:
                result.append((x, y))
            if next_x > x2:
                result.append((x2, y+(next_y-y)*(x2-x)/(next_x-x)))
        x, y = polyline[-1]
        if x1 < x <= x2:
            result.append((x, y))
        #assert result == sorted(result), result
        return result    

    def piece(x1, x2):
        result = part(lower, x1, x2)
        result.reverse()
        result.extend(part(upper, x1, x2))
        return result


    print>>fout

    #print part(lower, 0, W)
    #print piece(0, W)
    s = area(piece(0, W))
    hz = 1e-9
    #print s
    for i in range(1, G):
        f = lambda x: area(piece(0, x))
        x = func_bisect(f , s*i/G, 0, W)
        #print f(x)
        print>>fout, x
    #print '***'



###################################

class ListIterator(object):
    def __init__(self, list):
        self.list = list
        self.i = 0

    def next(self):
        if self.i >= len(self.list):
            raise StopIteration()
        self.i += 1
        return self.list[self.i-1]


def task(fin):
   fout = StringIO()
   solve(fin, fout)
   sys.stderr.write('.')
   return fout.getvalue()


if __name__ == '__main__':
    if len(sys.argv) != 2:
        print 'specify input file'
        exit()

    startTime = time.clock()

    fin = open(sys.argv[1])
    lines = fin.readlines()
    fin.close()

    fin = ListIterator(lines)

    numCases = int(next(fin))

    fins = []

    for caseNo in range(numCases):
        fins.append(copy(fin))
        solve(fin, None, only_read=True)
    try:
        next(fin)
        assert False, 'not all lines are processed'
    except StopIteration:
        pass

    print>>sys.stderr, '['+' '*len(fins)+']'
    sys.stderr.write('[')

    if mp:
        pool = multiprocessing.Pool()
        results = pool.map(task, fins)
    else:
        results = map(task, fins)

    sys.stderr.write(']\n')

    fout = open(os.path.splitext(sys.argv[1])[0]+'.out', 'w')
    for caseNo, answer in enumerate(results):
        print>>fout, 'Case #%s:'%(caseNo+1), answer,
    fout.close()

    print '\b'*10+'it took %.1fs'%(time.clock()-startTime)