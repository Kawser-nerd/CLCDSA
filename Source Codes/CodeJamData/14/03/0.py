
import math
import itertools
import numpy as NP

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

################################################################################

def read_case(f):
    return read_ints(f)

def write_case(f, i, res):
    f.write('Case #%d: '%i)
    if isinstance(res, list):
        res[0][0] = 'c'
        res = '\n'.join(''.join(c for c in r) for r in res)
    f.write('\n%s'%res)
    f.write('\n')

################################################################################

def solve_small(case):
    (R, C, M) = case
    if R == 1:
        return 'c' + '.'*(C-M-1) + '*'*M
    if C == 1:
        return '\n'.join(['c'] + ['.']*(R-M-1) + ['*']*M)
    m = R*C - M
    res = [['*']*C for r in range(R)]
    if m == 1:
        return res
    for r in range(2, R+1):
        c = m // r
        z = m % r
        if c < 2 or c + (z>0) > C:
            continue
        if z == 1 and (r < 3 or c < 3):
            continue
        for x in range(r):
            for y in range(c):
                res[x][y] = '.'
        for y in range(z):
            res[y][c] = '.'
        if z == 1:
            res[z][c] = '.'
            res[r-1][c-1] = '*'
        return res
    return 'Impossible'

def solve_large(case):
    return solve_small(case)

DEBUG = 'f'

from run import *
