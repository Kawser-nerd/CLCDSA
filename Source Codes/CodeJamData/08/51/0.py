#!/usr/bin/env python2.5
import math, sys, os, re
from collections import defaultdict

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

def run_file(file, out=None):
    if out is None and isinstance(file, basestring) and file.endswith('.in'):
        out = file[:-3]+'.out'
    if out is None: outfile = sys.stdout
    else: outfile = open(out, 'w')
    if isinstance(file, basestring): file = open(file)

    ncases = getint(file)
    for case in xrange(ncases):
        nparts = getint(file)
        moves = []
        while nparts > 0:
            chunks = file.readline().strip().split()
            for i in range(0, len(chunks), 2):
                moves.extend(list(chunks[i]) * int(chunks[i+1]))
                nparts -= 1
        assert nparts == 0
        if DEBUG: print ''.join(moves)

        answer = run_case(moves)
        print >> outfile, "Case #%d: %s" % (case+1, answer)

def run_case(moves):
    vertwalls = defaultdict(set)
    horzwalls = defaultdict(set)

    dx, dy = 0, 1
    x, y = 0, 0
    maxx, maxy, minx, miny = 0, 0, 0, 0
    for step in moves:
        if step == 'L': dx, dy = -dy, dx
        elif step == 'R': dx, dy = dy, -dx
        elif step == 'F':
            if dy == 1:
                vertwalls[y].add(x)
            elif dy == -1:
                vertwalls[y-1].add(x)
            elif dx == 1:
                horzwalls[x].add(y)
            elif dx == -1:
                horzwalls[x-1].add(y)
            x += dx
            y += dy
            if x > maxx: maxx = x
            if x < minx: minx = x
            if y > maxy: maxy = y
            if y < miny: miny = y

    pocket = 0
    for col in range(minx-1, maxx+2):
        walls = horzwalls[col]
        #assert len(walls) % 2 == 0
        if len(walls) < 4: continue

        swalls = sorted(list(walls))
        relevant = swalls[1:-1]
        for i in range(0, len(relevant), 2):
            start, end = relevant[i:i+2]
            pocket += end-start
            for row in range(start, end):
                if col in vertwalls[row]: vertwalls[row].remove(col)
                else: vertwalls[row].add(col)
                if col+1 in vertwalls[row]: vertwalls[row].remove(col+1)
                else: vertwalls[row].add(col+1)
    
    for row in range(miny-1, maxy+2):
        walls = vertwalls[row]
        #assert len(walls) % 2 == 0
        if len(walls) < 4: continue

        swalls = sorted(list(walls))
        relevant = swalls[1:-1]
        for i in range(0, len(relevant), 2):
            start, end = relevant[i:i+2]
            pocket += end-start
    return pocket

if __name__ == '__main__':
    import sys
    if len(sys.argv) > 1: run_file(sys.argv[1])
    else: run_file(sys.stdin)

