#!/usr/bin/env python2.5
import math, sys, os, re
from Queue import Queue
import numpy # http://numpy.scipy.org

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
        rows, cols = getints(file)
        yourow = youcol = cakerow = cakecol = 0
        terrain = numpy.zeros((rows+2, cols+2), 'i')
        for row in range(rows):
            rowtext = file.readline().strip()
            for col in range(cols):
                if rowtext[col] == 'O':
                    yourow = row+1
                    youcol = col+1
                elif rowtext[col] == 'X':
                    cakerow = row+1
                    cakecol = col+1
                elif rowtext[col] == '#':
                    terrain[row+1, col+1] = 1
        terrain[0,:] = 1
        terrain[rows+1, :] = 1
        terrain[:, 0] = 1
        terrain[:, cols+1] = 1
        answer = run_case(terrain, yourow, youcol, cakerow, cakecol)
        print >> outfile, "Case #%d: %s" % (case+1, answer)

def run_case(terrain, yourow, youcol, cakerow, cakecol):
    rows, cols = terrain.shape
    moves = terrain*0 + 1000000
    walldist = (1 - terrain) * 1000000
    for iter in range(32):
        for row in range(1, rows-1):
            for col in range(1, cols-1):
                walldist[row, col] = min(walldist[row, col],
                  walldist[row+1, col] + 1,
                  walldist[row-1, col] + 1,
                  walldist[row, col+1] + 1,
                  walldist[row, col-1] + 1)
    
    q = Queue()
    q.put((cakerow, cakecol))
    moves[cakerow, cakecol] = 0

    while not q.empty():
        currow, curcol = q.get(block=False)
        if DEBUG: print currow, curcol
        curmoves = moves[currow, curcol]
        for orow, ocol in [(currow+1, curcol), (currow-1, curcol),
                           (currow, curcol+1), (currow, curcol-1)]:
            if terrain[orow, ocol] != 1 and curmoves+1 < moves[orow, ocol]:
                q.put((orow, ocol))
                moves[orow, ocol] = curmoves+1

        wpr, wpc = currow, curcol
        if terrain[wpr+1, wpc] == 1:
            while terrain[wpr, wpc] != 1:
                if curmoves+walldist[wpr, wpc] < moves[wpr, wpc]:
                    q.put((wpr, wpc))
                    moves[wpr, wpc] = curmoves+walldist[wpr, wpc]
                wpr -= 1
        
        wpr, wpc = currow, curcol
        if terrain[wpr-1, wpc] == 1:
            while terrain[wpr, wpc] != 1:
                if curmoves+walldist[wpr, wpc] < moves[wpr, wpc]:
                    q.put((wpr, wpc))
                    moves[wpr, wpc] = curmoves+walldist[wpr, wpc]
                wpr += 1
        
        wpr, wpc = currow, curcol
        if terrain[wpr, wpc+1] == 1:
            while terrain[wpr, wpc] != 1:
                if curmoves+walldist[wpr, wpc] < moves[wpr, wpc]:
                    q.put((wpr, wpc))
                    moves[wpr, wpc] = curmoves+walldist[wpr, wpc]
                wpc -= 1
        
        wpr, wpc = currow, curcol
        if terrain[wpr, wpc-1] == 1:
            while terrain[wpr, wpc] != 1:
                if curmoves+walldist[wpr, wpc] < moves[wpr, wpc]:
                    q.put((wpr, wpc))
                    moves[wpr, wpc] = curmoves+walldist[wpr, wpc]
                wpc += 1
    if DEBUG: print walldist
    if DEBUG: print moves 
    if moves[yourow, youcol] >= 1000000: return "THE CAKE IS A LIE"
    return moves[yourow, youcol]

if __name__ == '__main__':
    import sys
    if len(sys.argv) > 1: run_file(sys.argv[1])
    else: run_file(sys.stdin)

