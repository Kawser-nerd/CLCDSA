#!/usr/bin/env python

import math
import sys
import logging
import re
from collections import defaultdict
import tempfile

testdata = '''6
2 1
500 300
900
660
2 1
500 300
1500
809
2 2
50 100
450 449
1100 1101
2 1
500 300
300
500
1 8
10
11 13 17 11 16 14 12 18
3 3
70 80 90
1260 1500 700
800 1440 1600
1700 1620 900
'''

def readstr(fhandle):
    return fhandle.readline().strip()

def readone(fhandle):
    return int(fhandle.readline().strip())

def readint(fhandle):
    return readone(fhandle)

def readmult(fhandle):
    return tuple(fhandle.readline().strip().split())

def readmultint(fhandle):
    return tuple(int(x) for x in readmult(fhandle))

def readfirst(fhandle):
    ncases = readone(fhandle)
    return ncases

def nextcase(fhandle,params=None):
    n,p = readmultint(fhandle)
    r = readmultint(fhandle) # N recipe elements
    assert len(r) == n
    q = []
    for i in range(n):
        q.append(readmultint(fhandle))
        assert len(q[-1]) == p
    logging.info('Test: %s %s', r, q)
    return solve(r,q,p)

def solve(R,Q,P):
    Q_new = []
    for q in Q:
        Q_new.append(sorted(list(q)))
    Q = Q_new
    indices = [0] * len(R)

    valid_count = 0
    scalar = 1
    while max(indices) < P:
        is_valid = True
        for i,arr in enumerate(Q):
            # arr[indices] must be within [0.9,1.1]*scalar*R[i]
            while indices[i] < P and arr[indices[i]] < 0.9*scalar*R[i]:
                indices[i] += 1
            if indices[i] >= P:
                is_valid = False
                break
            if arr[indices[i]] > 1.1*scalar*R[i]:
                scalar += 1
                is_valid = False
                break
        if is_valid:
            valid_count += 1
            logging.debug('valid: %d %s', scalar, indices)
            logging.debug('valid: %d %s', scalar, [Q[i][indices[i]] for i in range(len(Q))])
            indices = [i+1 for i in indices]
    return valid_count

if __name__ == '__main__':
    
    import argparse
    parser = argparse.ArgumentParser()
    parser.add_argument('--test',help='test cases',action='store_true',default=False)
    parser.add_argument('-d','--debug',action='count',default=0)
    parser.add_argument('inputfile',nargs='?')
    args = parser.parse_args()

    if args.debug >= 1:
        logging.basicConfig(level=logging.DEBUG,stream=sys.stdout)
    else:
        logging.basicConfig(level=logging.CRITICAL,stream=sys.stderr)

    ifhandle = sys.stdin
    if args.inputfile:
        ifhandle = open(args.inputfile)
    if args.test:
        ifhandle = tempfile.TemporaryFile()
        ifhandle.write(testdata)
        ifhandle.seek(0)
    ofhandle = sys.stdout

    nparams, ncases = 0, readfirst(ifhandle)

    # parameter reading
    logging.debug('%d parameters', nparams)
    for i in range(nparams):
        pass

    # test case reading
    logging.debug('%d cases', ncases)
    for i in range(ncases):
        ans = nextcase(ifhandle)
        outstr = 'Case #%d: %s' % (i+1, ans)
        logging.info(outstr)
        print >>ofhandle, outstr

    logging.info('Complete')
