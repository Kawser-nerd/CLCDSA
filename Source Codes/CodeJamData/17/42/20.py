import glob, pprint, pickle, os, time, sys
from copy import copy
import heapq
from numpy import array, sin, cos, zeros
import itertools
import math
import numpy as np
import bisect

RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET = "R","O","Y","G","B","V"
def solve(N,C,M,T):
    # N = seats
    # C = customers
    # T = tickets = (place, buyer)
    T = [(t[0]-1, t[1]-1) for t in T]
    print T
    N = min(N, 1+max([t[0] for t in T]))
    C = min(C, 1+max([t[1] for t in T]))
    t_per_c = [sorted([c for c in T if c[1]==i]) for i in xrange(C)]
    t_per_p = [sorted([c for c in T if c[0]==i]) for i in xrange(N)]

    # find number of trains:
    # underbound:
    sold = [0]
    for tpp in t_per_p:
        sold.append(sold[-1] + len(tpp))
    sold = sold[1:]
    # print sold
    for i in xrange(len(sold)):
        sold[i] = (sold[i]+i)/(i+1)
    # print sold

    underbound1 = max(sold)
    underbound2 = max([len(tpc) for tpc in t_per_c])
    carts = max(underbound1, underbound2)

    # how many promotions do we need for these carts?
    solution = [[None for n in xrange(N)] for m in xrange(carts)]

    sold = [0]
    for tpp in t_per_p:
        sold.append(len(tpp))
    sold = sold[1:]
    bumps = 0
    print sold
    for s in sold:
        bumps += max((s-carts),0)

    # print sold


    # construct carts (no more than 1000 tickets)
    # lower N and C
    # print N,C
    # N = min(N, 1+max([t[0] for t in T]))
    # C = min(C, 1+max([t[1] for t in T]))
    # print N,C
    #
    # solution = [[None for n in xrange(N)] for m in xrange(M)]
    # print solution, T
    # for i,tpc in enumerate(t_per_c):
    #     j = 0
    #     for t in tpc:
    #         while solution[j][t[0]] is not None:
    #             j+=1
    #             print j, M
    #         solution[j][t[0]] = t
    #
    # print solution
    #
    # print N,C,M,T
    return carts,bumps


output = ""
TIC = time.time()
with open(sys.argv[1] if len(sys.argv) > 1 else "default.in") as f:
    def read_ints():
        return [int(x) for x in f.readline().strip().split(' ')]
    def read_frac():
        return [int(x) for x in f.readline().strip().split('/')]
    def read_strs():
        return [x for x in f.readline().strip().split(' ')]
    def read_floats():
        return [float(x) for x in f.readline().strip().split(' ')]

    (numquestions,) = read_ints()
    for questionindex in xrange(numquestions):

        ### calculate answer ###
        N,C,M = read_ints()
        t = []
        for m in xrange(M):
            t.append(read_ints())

        answer = solve(N,C,M,t)

        ### output ###
        answer_str = "Case #{}: {}".format(questionindex+1, " ".join([str(a) for a in answer]) if isinstance(answer, tuple) else answer)
        output += answer_str + '\n'
        print answer_str

ofile = open('output', 'w').write(output)
TOC = time.time()