#!/usr/bin/python
__author__ = 'Tianren Liu'

import sys
import numpy as np
from pulp import *

def solve(N, lines):
    lset = [set(line.split()) for line in lines]
    L = [0,1] + [LpVariable("l{}".format(n), 0,1) for n in range(2,N)]

    wset = set.union(*lset)
    Wmax = {w:LpVariable("wmax{}".format(w)) for w in wset}
    Wmin = {w:LpVariable("wmin{}".format(w)) for w in wset}

    prob = LpProblem("problem", LpMinimize)

    prob += sum(Wmax.values())-sum(Wmin.values())
    for w in wset:
        for i in range(N):
            if w in lset[i]:
                prob += Wmax[w] >= L[i]
                prob += Wmin[w] <= L[i]

    status = prob.solve(GLPK(msg=0))
    # LpStatus[status]

    return int(sum([value(e) for e in Wmax.values()]) - sum([value(e) for e in Wmin.values()])+0.5)
    
if __name__ == "__main__":
    T = int(sys.stdin.readline())
    for t in xrange(T):
        N = int(sys.stdin.readline())
        print( "Case #{}: {}".format(t+1, solve(N, [sys.stdin.readline() for n in range(N)]) )) 
