import math
from time import time
import itertools
import operator
from sys import *
from heapq import *
from time import time
from multiprocessing import Pool
from collections import *
import itertools
from copy import deepcopy
from bisect import *
setrecursionlimit(10000)
from math import *
from time import sleep
import os
import sys
import re
import numpy as np
import heapq

def readint():
    return int(fi.readline())

def readints():
    return [int(X) for X in fi.readline().split()]

def read_case():
    (N,D) = readints()
    (S0, AS, CS, RS) = readints()
    (M0, Am, Cm, Rm) = readints()
    S = [S0]
    M = [M0]
    E = [list() for _ in range(N)]
    for I in xrange(1,N):
        S.append((S[-1] * AS + CS) % RS)
        M.append((M[-1] * Am + Cm) % Rm)
    for I in xrange(1,N):
        M[I] = M[I] % I
    return (D, N, S, M)

def cost(lb, ub, N, E, S, count):
    cost = [0 for _ in xrange(N)]
    for e in xrange(N-1,-1,-1):
        if S[e] > ub or S[e] < lb: cost[e] = count[e]
        else: cost[e] = sum(cost[k] for k in E[e])
    return cost[0]

def solve_case(D, N, S, M):
    if N == 1: return 1
    E = [list() for _ in xrange(N)]
    for I in range(1,N):
        E[M[I]].append(I)
    count = [0 for _ in xrange(N)]
    for e in xrange(N-1,-1,-1):
        count[e] = 1 + sum(count[k] for k in E[e])
    best = 99999999
    for lb in range(S[0]-D, 1+S[0]):
        c = cost(lb, lb+D, N, E, S, count)
        if c < best: best = c
    return N - best

def print_solution(case):
    val = solve_case(*case[1])
    msg = "Case #{}: {}".format(case[0], val)
    print(msg)
    return msg

t0 = time()
t1 = time()
print("Intialisation took %f seconds" % (t1 - t0))
if (t1-t0 > 5): input("Press Enter to continue...")
t1 = time()

if __name__ == '__main__':
    fni = "%s-%s-%s.in" % (argv[1], argv[2], argv[3])
    fno = "%s-%s-%s.out" % (argv[1], argv[2], argv[3])

    if not os.path.isfile(fni):
        sys.stdout.write('Waiting for input file {}...'.format(fni))
        while not os.path.isfile(fni):
            sys.stdout.flush()
            sleep(1)
            sys.stdout.write(".")
        sleep(1)
        print('')
    fi = open(fni, 'r')

    numcases = readint()
    cases = [(I, read_case()) for I in range(1,1+numcases)]

    mt = False
    if mt:
        print("Running multi-threaded")
        p = Pool(8)
        output = list(p.map(print_solution, cases))
    else:
        print("Running single-threaded")
        output = list(map(print_solution, cases))
    print("Elapsed time %f seconds " % (time() - t1))

    if os.path.isfile(fno):
        print('Verifying against existing results')
        fo = open(fno, 'r')
        oc = re.split('(Case #[0-9]+:\s*)', fo.read())[1:]
        refout = [(A+B).rstrip() for (A,B) in zip(oc[::2], oc[1::2])]
        diffs = 0
        for C in range(numcases):
           if refout[C] != output[C]:
               print('-'*20)
               print('Input {}\nReference Output {}\nGenerated Output {}'.format(cases[C][1], refout[C], output[C]))
               print('-'*20)
               diffs += 1
        print('{} diffs found'.format(diffs))
    else:
        fo = open(fno, 'w')
        fo.write('\n'.join(output))
        print('{} cases written'.format(len(output)))

