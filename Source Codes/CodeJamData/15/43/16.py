"""Usage:
    pypy -u X.py < X-test.in > X-test.out
or sometimes
    python -u X.py < X-test.in > X-test.out
"""

import os
import sys
#sys.setrecursionlimit(20000)


def common_setup():
    #import memcache as mc
    #C = mc.Client(['127.0.0.1:11211'])
    pass


def case_reader(tc, infile):
    N = int(next(infile))
    #P = map(int, next(infile).split())
    #I = [map(int, next(infile).split()) for _ in range(P[0])]
    #T = next(infile).split()
    S = [next(infile).strip().split() for _ in range(N)]
    return locals()


def case_solver(tc, N=None, P=None, I=None, T=None, S=None, **kwargs):
    #import collections as co
    #import functools32 as ft
    #import itertools as it
    #import math as ma
    import networkx as nx
    #import numpy as np
    #import operator as op
    #import random as rn
    #import re
    #import scipy as sp
    #import heapq as hq
    #import memcache as mc
    #C = mc.Client(['127.0.0.1:11211'])

    pid = os.getpid()

    S[0] += ['0']
    S[1] += ['1']
    S = map(frozenset, S)

    G = nx.Graph()
    for i, s1 in enumerate(sorted(S)):
        for s2 in sorted(S)[i+1:]:
            if s1 == s2:
                continue
            cw = s1 & s2
            for w in cw:
                G.add_edge(s1, w, capacity=1)
                G.add_edge(w, s2, capacity=1)

    return 'Case #{:d}: {}'.format(tc, nx.minimum_cut(G, S[0], S[1])[0])


if __name__ == '__main__':
    common_setup()
    cases = [case_reader(tc, sys.stdin) for tc in range(1, int(next(sys.stdin)) + 1)]
    for case in cases:
        print case_solver(**case)
