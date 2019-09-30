#!/usr/bin/env python

import math
import sys
import logging
import re
from collections import defaultdict
import tempfile

testdata = '''3
3 3
G??
?C?
??J
3 4
CODE
????
?JAM
2 2
CA
KE
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
    r,c = readmultint(fhandle)
    arr = [readstr(fhandle) for i in range(r)]
    logging.info('Test: %s', arr)
    return solve(arr,r,c)

def solve(arr,R,C):
    cake = {}
    orig_cake = {}
    for r in range(R):
        for c in range(C):
            cake[r,c] = arr[r][c]
            orig_cake[r,c] = arr[r][c]
    for r in range(R):
        for c in range(C):
            if orig_cake[r,c] == '?':
                continue
            r_up,r_down=0,1
            c_left,c_right=0,1
            logging.debug('starting search %d %d %s', r,c, cake[r,c])

            while c+c_left >= 1:
                is_valid = True
                for x in range(r+r_up,r+r_down):
                    logging.debug('<- %d %d %d', c,c_left,x)
                    if cake[x,c+c_left-1] != '?':
                        is_valid = False
                        break
                if is_valid:
                    c_left = c_left-1
                else:
                    break

            while c+c_right < C:
                is_valid = True
                for x in range(r+r_up,r+r_down):
                    logging.debug('-> %d %d %d', c,c_right,x)
                    if cake[x,c+c_right] != '?':
                        is_valid = False
                        break
                if is_valid:
                    c_right = c_right+1
                else:
                    break

            while r+r_up >= 1:
                is_valid = True
                for x in range(c+c_left,c+c_right):
                    if cake[r+r_up-1,x] != '?':
                        is_valid = False
                        break
                if is_valid:
                    r_up -= 1
                else:
                    break

            while r+r_down < R:
                is_valid = True
                for x in range(c+c_left,c+c_right):
                    if cake[r+r_down,x] != '?':
                        is_valid = False
                        break
                if is_valid:
                    r_down += 1
                else:
                    break

            logging.debug('fill r=[%d,%d], c=[%d,%d]', r+r_up, r+r_down, c+c_left, c+c_right)
            for r0 in range(r+r_up,r+r_down):
                for c0 in range(c+c_left,c+c_right):
                    cake[r0,c0] = cake[r,c]
                

                
            st = ''
            for r0 in range(R):
                st = st + '\n'
                for c0 in range(C):
                    st = st + cake[r0,c0]
            logging.debug('cake: %s', st)
    return st

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
