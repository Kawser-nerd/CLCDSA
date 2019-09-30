#! /usr/bin/python3.1

import sys
from sys import maxsize
import os
import itertools
import multiprocessing

MEMO = {}

def symat(k, lines, r, c):
    nlines = len(lines)
    minr = r - min(r, nlines - r - 1)
    for i1 in range(r - 1, minr - 1, -1):
        i2 = r + (r - i1)
        line1 = lines[i1]
        line2 = lines[i2]
        for j in range(nlines):
            a, b = line1[j], line2[j]
            if a == ' ' or b == ' ':
                continue
            if a != b:
                return False
    minc = c - min(c, nlines - c - 1)
    for line in lines:
        for i1 in range(c - 1, minc - 1, -1):
            i2 = c + (c - i1)
            a, b = line[i1], line[i2]
            if a == ' ' or b == ' ':
                continue
            if a != b:
                return False
    print([r, c], file=sys.stderr)
    return True

def symdist(k, lines):
    queue = [(k - 1, k - 1)]
    d = 0
    tried = set(queue)
    next = []
    while True:
        for r, c in queue:
            if symat(k, lines, r, c):
                return d
            nlines = len(lines)
            for coords in ((r - 1, c), (r + 1, c),
                           (r, c - 1), (r, c + 1)):
                i, j = coords
                if i >= nlines or i < 0:
                    continue
                if j >= nlines or j < 0:
                    continue
                if coords not in tried:
                    next.append(coords)
                    tried.add(coords)
        d += 1
        queue, next = next, queue
        del next[:]
    return None

def solve(case):
    ncase, case = case
    print("Solving #{0}: {1}".format(ncase, case), file=sys.stderr)
    k, lines = case
    MEMO.clear()
    d = symdist(k, lines)
    k1 = k + d
    result = (k1 * k1) - (k * k)
    return (ncase, result)

def read_cases(inf):
    ncases = int(inf.readline().strip())
    cases = []
    for i in range(1, ncases + 1):
        k = int(inf.readline().strip())
        lines = []
        nlines = (2 * k) - 1
        for j in range(nlines):
            line = inf.readline()[:-1]
            line += (" " * (nlines - len(line)))
            lines.append(line)
        case = (i, (k, lines))
        cases.append(case)
    return cases

def get_ncores():
    with open('/proc/cpuinfo') as f:
        cores = [x for x in f.readlines() if x.startswith('processor\t:')]
    return len(cores)

def main(argv=sys.argv):
    cases = read_cases(sys.stdin)
    pool = multiprocessing.Pool(processes=get_ncores())
    results = pool.map(solve, cases)
    #results = map(solve, cases)
    for i, result in results:
        print("Case #{0}: {1}".format(i, result))
    return 0
        
if __name__ == '__main__':
    sys.exit(main())
