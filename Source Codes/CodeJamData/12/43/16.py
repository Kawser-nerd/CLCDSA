
import math
import itertools
import numpy

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
    res = []
    for i in range(R):
        res.append(reader(f, *args, **kwargs))
    return res

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

################################################################################

def read_case(f):
    N = read_int(f)
    X = read_ints(f)
    return (N, X)

def write_case(f, i, res):
    f.write('Case #%d: '%i)
    f.write('%s'%res)
    f.write('\n')

################################################################################

def aux(X, start, end, res, depth):
    i = start
    res[i] = res[end] - depth*(end-i)
    while i < end:
        j = X[i-1]
        if j > end:
            return False
        res[j] = res[end] - depth*(end-j)
        if j > i+1:
            if not aux(X, i+1, j, res, depth+1):
                return False
        i = j
    return True

FAIL = 'Impossible'

def solve_small(case):
    (N, X) = case
    res = [None]*(N+1)
    res[-1] = 10**9
    if not aux(X, 1, N, res, 0):
        return FAIL
    for i in range(1, N):
        x = X[i-1]
    return ' '.join('%d'%r for r in res[1:])

def solve_large(case):
    return solve_small(case)

DEBUG = 'f'

from run import *
