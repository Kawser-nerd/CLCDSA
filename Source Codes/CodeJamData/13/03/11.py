
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
    return read_ints(f)

def write_case(f, i, res):
    f.write('Case #%d: '%i)
    f.write('%d'%res)
    f.write('\n')

################################################################################

def aux(A, B, x, s):
    res = 0
    n = int(''.join(x[::-1]+x))
    nn = n*n
    if nn > B:
        return res
    if nn >= A:
        res += 1
    for c in [0, 1, 2]:
        if s + c*c < 10:
            n = int(''.join(x[::-1]+[str(c)]+x))
            nn = n*n
            if nn >= A and nn <= B:
                res += 1
        if s + 2*c*c < 10:
            res += aux(A, B, [str(c)]+x, s + 2*c*c)
    return res

def solve_small(case):
    [A, B] = case
    res = 0
    for n in [1, 4, 9]:
        if n >= A and n <= B:
            res += 1
    for c in [1, 2]:
        res += aux(A, B, [str(c)], 2*c*c)
    return res

def solve_large(case):
    return solve_small(case)

DEBUG = 'i'

from run import *
