"""Usage:
    X.py < X.in > X.out
"""

def setup(infile):
    #C = {}
    return locals()

def reader(testcase, infile, **ignore):
    #N = int(infile.next())
    P = map(int, infile.next().split())
    I = map(int, infile.next().split())
    #T = infile.next().split()
    S = [map(int, infile.next().split()) for i in range(P[1])]
    return locals()

def solver(infile, testcase, N=None, P=None, I=None, T=None, S=None, C=None, **ignore):
    #import collections as co
    #import functools as ft
    #import itertools as it
    #import operator as op
    #import math as ma
    #import re
    #import numpy as np
    #import scipy as sp
    #import networkx as nx
    import lrucache as lc

    K, N = P

    Ki = sorted(I)

    S = [[i]+t for i, t in enumerate(S,1)]

    T = [(t[1], tuple(t[3:]), t[0]) for t in S]

    def topen(t, Ki, T):
        Ki = list(Ki)
        Ki.remove(T[t][0])
        Ki.extend(T[t][1])
        Ki.sort()
        T = list(T)
        T.pop(t)
        return tuple(Ki), tuple(T)

    @lc.lru_cache(maxsize=None)
    def seq(Ki, T):
        #print Ki, T
        if len(T)==1 and T[0][0] in Ki:
            return [T[0][2]]
        todo = set(t[0] for t in T)
        if len(todo & set(Ki)) == 0:
            return None
        for t in range(len(T)):
            if T[t][0] not in Ki:
                continue
            nKi, nT = topen(t, Ki, T)
            nexts = seq(nKi, nT)
            if nexts is None:
                continue
            return [T[t][2]] + nexts
        return None


    res = seq(tuple(Ki), tuple(T))
    if res == None:
        res = 'IMPOSSIBLE'
    else:
        res =  ' '.join('%d'%n for n in res)
    return 'Case #%s: %s\n' % (testcase, res)

if __name__ == '__main__':
    import sys
    T = int(sys.stdin.next())
    common = setup(sys.stdin)
    for t in xrange(1, T+1):
        sys.stdout.write(solver(**reader(t, **common)))
