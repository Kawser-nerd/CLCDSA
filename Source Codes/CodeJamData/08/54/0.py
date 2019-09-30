#!/usr/bin/env python2.5
import math, sys, os, re, numpy
# http://numpy.scipy.org

# import psyco
# psyco.profile()

DEBUG = False
def getline(file, types):
    parts = file.readline().strip().split()
    got = []
    for i in xrange(len(parts)):
        got.append(types[i](parts[i]))
    return got

def getints(file):
    parts = file.readline().strip().split()
    return [int(x) for x in parts]

def getint(file):
    ints = getints(file)
    assert len(ints) == 1
    return ints[0]

def rock2move(x, y):    
    xp, yp = x-1, y-1
    if (xp+yp)%3 != 0: return (None, None)
    else: 
        off, moves = yp-xp, (xp+yp)/3
        return ((off+moves) / 2), ((moves-off) / 2)

def run_file(file, out=None):
    if out is None and isinstance(file, basestring) and file.endswith('.in'):
        out = file[:-3]+'.out'
    if out is None: outfile = sys.stdout
    else: outfile = open(out, 'w')
    if isinstance(file, basestring): file = open(file)


    ncases = getint(file)
    for case in xrange(ncases):
        H, W, R = getints(file)
        gh, gw = rock2move(H, W)
        rocks = []
        if DEBUG: print gh, gw
        for r in range(R):
            x, y = getints(file)
            r, c = rock2move(x, y)
            if DEBUG: print '\t', r, c
            if r is not None: rocks.append((r, c))
        answer = run_case(gh, gw, rocks)
        print >> outfile, "Case #%d: %s" % (case+1, answer)

def run_case(gh, gw, rocks):
    if gh is None: return 0
    grid = numpy.zeros((gh+2, gw+2), 'i')
    grid[gh, gw] = 1
    for r, c in rocks:
        if 0 <= r <= gh and 0 <= c <= gw:
            grid[r, c] = -1
    for r in range(gh, -1, -1):
        for c in range(gw, -1, -1):
            if grid[r, c] == -1: continue
            if (r, c) == (gh, gw): continue
            grid[r, c] = (max(grid[r+1, c], 0) + max(grid[r, c+1], 0)) % 10007
    return grid[0, 0]

if __name__ == '__main__':
    import sys
    if len(sys.argv) > 1: run_file(sys.argv[1])
    else: run_file(sys.stdin)

