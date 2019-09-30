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
        [N, K] = rint()
        S = rint()
        M = []
        rtt = 0
        for x in xrange(K):
            a = 0
            V = [0]
            for y in xrange(x, N-K, K):
                a += S[y+1] - S[y]
                V.append(a)
            rtt += len(V)
            M.append((min(V), max(V)))
#        print M
        assert rtt == N
        D = [ma - mi for (mi, ma) in M]
        d = max(D)
#        print D
        di = D.index(d)

        (MI, MA) = zip(*M)
#        mmi = min(MI)
        hmi = sum(MI[di] - m for m in MI)
#        mma = max(MA)
        hma = sum(MA[di] - m for m in MA)
#        print hmi, hma
        d += 0 if ((hma - S[0]) / K > (hmi - 1 - S[0]) / K) else 1

        T = str(d)
        print("Case #%i: %s" % (caseNr + 1, T ))
#        print("Case #%i:" % (caseNr + 1))
