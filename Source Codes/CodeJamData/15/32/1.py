
import math
import itertools
import numpy as NP

################################################################################

def read_case(f):
    K, L, S = read_ints(f)
    M = read_word(f)
    T = read_word(f)
    return K, L, S, M, T

def solve_small(case):
    K, L, S, M, T = case
    if L > S:
        return 0
    o = max(i for i in range(L) if T.endswith(T[:i]))
    m = (S - o) // (L - o)
    e = S - L + 1
    for l in T:
        e *= M.count(l) / K
    if e == 0:
        return 0
    return m - e

def solve_large(case):
    return solve_small(case)

def write_case(f, i, res):
    f.write('Case #%d: '%i)
    f.write('%f'%res)
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
