#!/usr/bin/env python
# -*- coding: utf-8 -*-
import math
import numpy as np
import sys
import copy
import random
from heapq import *
import itertools as it
import re
import collections as co

def rint():
    return map(int, raw_input().split())
def rfloat():
    return map(float, raw_input().split())

def rstr():
    return raw_input().split()

def rlist(*lfn):
    return  [f(a) for (f, a) in zip(lfn, raw_input().split())]
def fact(n):
    p = 1
    for i in xrange(1, n+1):
        p *= i
    return p

def rec_st(first, on_generate, on_execute):
    S = [(0, f) for f in first]
    while S:
        (k, cont) = S.pop()
        if k == 0:
            S.append((1, cont))
            for u in on_generate(cont):
                S.append((0, u))
        else:
            on_execute(cont)

def rec_q(first, on_generate):
    Q = co.deque(first)
    while Q:
        cont = Q.pop_left()
        for u in on_generate(cont):
            Q.append(u)

if __name__ == "__main__":
    testcases = input()
     
    for caseNr in xrange(testcases):
        [N, D] = rint()
        [S0, As, Cs, Rs] = rint()
        [M0, Am, Cm, Rm] = rint()
        S = S0
        M = M0
        U = []
        for i in xrange(N):
            U.append((S, M % i if i > 0 else -1))
            S = (S * As + Cs) % Rs
            M = (M * Am + Cm) % Rm
#        print U
        V = [None for _ in xrange(N)]
        E = []
#        def on_gen(u):
#            p = U[u][1]
##            print u, p
#            if (V[p] == None):
#                yield p
#        def on_exec(u):
#            p = U[u][1]
#            s = U[u][0]
#            assert V[p] != None
#            (mi, ma) = V[p]
#            V[u] = (min(mi, s), max(ma, s))
#        V[0] = (S0, S0)
#        for i in xrange(1, N):
#            if (V[i] == None):
#                rec_st([i], on_gen, on_exec)
        for i in xrange(N):
            p = U[i][1]
            (mi, ma) = V[p] if p != -1 else (S0, S0)
            s = U[i][0]
            V[i] = (min(mi, s), max(ma, s))
            (mi, ma) = V[i]
            if ma - mi <= D:
                E.append((ma, -1))
                E.append((mi + D, +1))

        E = sorted(E)
        ct = 0
        mx = 0
        for (t, ev) in E:
            mx = max(mx, ct)
            ct -= ev
            assert (ct >= 0)
            mx = max(mx, ct)

#        print E

        T = str(mx)
        print("Case #%i: %s" % (caseNr + 1, T ))
#        print("Case #%i:" % (caseNr + 1))
