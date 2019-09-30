"""Usage:
    X.py < X.in > X.out
"""

def setup(infile):
    #C = {}
    return locals()

def reader(testcase, infile, **ignore):
    #N = int(infile.next())
    #P = map(int, infile.next().split())
    #I = map(int, infile.next().split())
    #T = infile.next().split()
    S = [infile.next().strip() for i in range(5)]
    return locals()

def solver(infile, testcase, N=None, P=None, I=None, T=None, S=None, C=None, **ignore):
    #import collections as co
    #import functools as ft
    import itertools as it
    #import operator as op
    #import math as ma
    #import re
    #import numpy as np
    #import scipy as sp
    #import networkx as nx
    
    not_draw = False
    for line in S[:4]:
        not_win = set()
        if '.' in line:
            not_draw = True
            continue
        if 'O' in line:
            not_win.add('X')
        if 'X' in line:
            not_win.add('O')
        if len(not_win) == 1:
            return 'Case #%s: %s\n' % (testcase, 'X won' if 'X' not in not_win else 'O won')

    ST = []
    for j in range(4):
        ST.append(''.join(S[i][j] for i in range(4)))
    for line in ST:
        not_win = set()
        if '.' in line:
            continue
        if 'O' in line:
            not_win.add('X')
        if 'X' in line:
            not_win.add('O')
        if len(not_win) == 1:
            return 'Case #%s: %s\n' % (testcase, 'X won' if 'X' not in not_win else 'O won')

    line = ''.join(S[i][i] for i in range(4))
    not_win = set()
    if '.' not in line:   
        if 'O' in line:
            not_win.add('X')
        if 'X' in line:
            not_win.add('O')
        if len(not_win) == 1:
            return 'Case #%s: %s\n' % (testcase, 'X won' if 'X' not in not_win else 'O won')

    line = ''.join(S[i][3-i] for i in range(4))
    not_win = set()
    if '.' not in line:
        if 'O' in line:
            not_win.add('X')
        if 'X' in line:
            not_win.add('O')
        if len(not_win) == 1:
            return 'Case #%s: %s\n' % (testcase, 'X won' if 'X' not in not_win else 'O won')

    if not_draw:
        return 'Case #%s: %s\n' % (testcase, 'Game has not completed')
    else:
        return 'Case #%s: %s\n' % (testcase, 'Draw')

if __name__ == '__main__':
    import sys
    T = int(sys.stdin.next())
    common = setup(sys.stdin)
    for t in xrange(1, T+1):
        sys.stdout.write(solver(**reader(t, **common)))
