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
    P = readint()
    return (readints(), readints())

def nCr(n, r):
    if (r > n): return 0
    if (r > n/2): r = n-r
    rv = 1
    for k in xrange(r):
        rv = (rv*(n-k))/(1+k)
    return rv

def reduce(sums, freq):
    elt = sums[1]
    ct = freq[1]
    f = {sums[I]: freq[I] for I in xrange(len(sums))}
    for I in xrange(len(sums)):
        for S in xrange(1,1+ct):
            p = sums[I] - S*elt
            if p in f:
                f[sums[I]] -= nCr(ct,S) * f[p]
    sums[:] = []
    freq[:]  = []
    for (S,F) in sorted(f.iteritems()):
        if F > 0:
            sums.append(S)
            freq.append(F)

def log2(X):
    L = 0
    while X > 1:
        X = X/2
        L += 1
    return L

def solve_case(sums, freq):
    ss = sorted(sums)
    zeroes = log2(freq[0])
    if (zeroes > 0):
        zf = freq[0]
        for I in range(len(freq)):
            freq[I] /= zf
    rv = [0] * zeroes
    while len(freq) > 1:
       rv.extend([sums[1]] * freq[1])
       print sums
       print freq
       reduce(sums, freq)
       print sums
       print freq
    return " ".join([str(X) for X in rv])

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

