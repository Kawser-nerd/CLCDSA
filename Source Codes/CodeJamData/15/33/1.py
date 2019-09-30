
import math
import itertools
import numpy as NP

################################################################################

def read_case(f):
    C, D, V = read_ints(f)
    M = read_ints(f)
    return C, D, V, M

def solve_small(case):
    C, D, V, M = case
    i = 0
    while i <= len(M):
        s = sum(M[:i]) + 1
        if s <= V and (len(M) == i or M[i] > s):
            M = M[:i] + [s] + M[i:]
        i += 1
    return len(M) - D

def solve_large(case):
    C, D, V, M = case
    i = 0
    while i <= len(M):
        s = C * sum(M[:i]) + 1
        if s <= V and (len(M) == i or M[i] > s):
            M = M[:i] + [s] + M[i:]
        i += 1
    return len(M) - D

def write_case(f, i, res):
    f.write('Case #%d: '%i)
    f.write('%s'%res)
    f.write('\n')

################################################################################

def read_word(f):
    return next(f).strip()

def read_int(f, b=10):
    return int(read_word(f), b)

def read_letters(f):
    return list(read_word(f))

def read_digits(f, b=10):
    return [int(x, b) for x in read_letters(f)]

def read_words(f, d=' '):
    return read_word(f).split(d)

def read_ints(f, b=10, d=' '):
    return [int(x, b) for x in read_words(f, d)]

def read_floats(f, d=' '):
    return [float(x) for x in read_words(f, d)]

def read_arr(f, R, reader=read_ints, *args, **kwargs):
    return [reader(f, *args, **kwargs) for i in range(R)]

def solve(solver, fn, out_fn=None):
    in_fn = fn + '.in'
    if out_fn is None:
        out_fn = fn + '.out'
    with open(in_fn, 'r') as fi:
        with open(out_fn, 'w') as fo:
            T = read_int(fi)
            for i in range(T):
                case = read_case(fi)
                res = solver(case)
                write_case(fo, i, res)

DEBUG = 'i'

from run import *
