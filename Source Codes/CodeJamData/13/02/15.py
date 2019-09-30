"""Usage:
    X.py < X.in > X.out
"""

def setup(infile):
    #C = {}
    return locals()

def reader(testcase, infile, **ignore):
    #N = int(infile.next())
    P = map(int, infile.next().split())
    #I = map(int, infile.next().split())
    #T = infile.next().split()
    S = [map(int, infile.next().split()) for i in range(P[0])]
    return locals()

def solver(infile, testcase, N=None, P=None, I=None, T=None, S=None, C=None, **ignore):
    #import collections as co
    #import functools as ft
    #import itertools as it
    #import operator as op
    #import math as ma
    #import re
    import numpypy as np
    #import scipy as sp
    #import networkx as nx
    
    S = np.array(S)
    done = np.zeros(P, dtype=int)
    for row in range(P[0]):
        m = S[row].max()
        done[row][S[row]==m] = 1

    for col in range(P[1]):
        m = S[:,col].max()
        done[:,col][S[:,col]==m] = 1

    res = 'YES' if done.sum() == P[0]*P[1] else 'NO'
    return 'Case #%s: %s\n' % (testcase, res)

if __name__ == '__main__':
    import sys
    T = int(sys.stdin.next())
    common = setup(sys.stdin)
    for t in xrange(1, T+1):
        sys.stdout.write(solver(**reader(t, **common)))
