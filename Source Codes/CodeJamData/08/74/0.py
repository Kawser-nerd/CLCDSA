#!/usr/bin/env python2.5
import math, sys, os, re

DEBUG = False
deltas = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]

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
        board = [list('#'*(cols+2))]
        king = None
        for r in range(rows):
            board.append(list('#%s#' % file.readline().strip()))
        board += [list('#'*(cols+2))]
        for r in range(rows+1):
            for c in range(cols+1):
                if board[r][c] == 'K':
                    king = (r, c)
                    board[r][c] = '#'

        print "Case", case
        answer = run_case(board, king[0], king[1])
        print >> outfile, "Case #%d: %s" % (case+1, answer)

def recurse(board, krow, kcol):
    board = [list(b) for b in board]
    board[krow][kcol] = '#'
    for delta in deltas:
        krnew = krow+delta[0]
        kcnew = kcol+delta[1]
        #for line in board: print line
        if board[krnew][kcnew] == '.':
            if not recurse(board, krnew, kcnew):
                return True
        
    return False

def run_case(board, krow, kcol):
    if recurse(board, krow, kcol): return 'A'
    else: return 'B'

if __name__ == '__main__':
    import sys
    if len(sys.argv) > 1: run_file(sys.argv[1])
    else: run_file(sys.stdin)

