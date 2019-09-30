#!/usr/bin/env python

import math
import sys
import logging
import re
from collections import defaultdict
import tempfile

testdata = '''5
11 5 16 5 0 0
3 1 3 2 2 0
3 1 3 2 1 0
2 1 5 1 1 1
11 5 16 5 0 0
3 1 3 2 2 0
3 1 3 2 1 0
2 1 5 1 1 1
93 1 90 45 0 1
42 1 23 25 3 6
96 1 94 48 0 1
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
    tup = readmultint(fhandle)
    logging.info('Test: %s', tup)
    return solve(tup)

# dynamic programming
solve_ans = {}
def solve_helper(tup):
    global solve_ans
    logging.debug('%s', tup)
    if tup in solve_ans:
        if solve_ans[tup] is None:
            logging.warning('recursion! %s', tup)
            solve_ans[tup] = -1
        return solve_ans[tup]
    (h,hd,ad,hk,ak,b,d) = tup
    if h <= 0:
        solve_ans[tup] = -1
        return -1
    if hk <= ad: # one hit kill
        return 1

    solve_ans[tup] = None
    ans1,ans2,ans3,ans4 = -1,-1,-1,-1

    # attack
    logging.debug('attack %s', tup)
    ans1 = solve_helper((h-ak,hd,ad,hk-ad,ak,b,d))
    if b > 0:
        # buff
        logging.debug('buff %s', tup)
        ans2 = solve_helper((h-ak,hd,ad+b,hk,ak,b,d))
    # cure
    logging.debug('cure %s', tup)
    ans3 = solve_helper((hd-ak,hd,ad,hk,ak,b,d))
    if d > 0:
        # debuff
        logging.debug('debuff %s', tup)
        ans4 = solve_helper((h-max(0,ak-d),hd,ad,hk,max(0,ak-d),b,d))

    arr = [ans1,ans2,ans3,ans4]
    arr = [x for x in arr if x >= 0]
    if len(arr) == 0:
        solve_ans[tup] = -1
    else:
        n = 1 + min(arr)
        solve_ans[tup] = n
    return solve_ans[tup]

def solve(tup):
    (hd,ad,hk,ak,b,d) = tup
    h = hd
    return solve_helper((h,hd,ad,hk,ak,b,d))

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
        if ans < 0:
            ans = 'IMPOSSIBLE'
        outstr = 'Case #%d: %s' % (i+1, ans)
        logging.info(outstr)
        print >>ofhandle, outstr

    logging.info('Complete')
