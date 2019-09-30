
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
    R1 = read_int(f)
    Q1 = read_arr(f, 4)
    R2 = read_int(f)
    Q2 = read_arr(f, 4)
    return (R1, Q1, R2, Q2)

def write_case(f, i, res):
    f.write('Case #%d: '%i)
    f.write('%s'%res)
    f.write('\n')

################################################################################

def solve_small(case):
    (R1, Q1, R2, Q2) = case
    s = set(Q1[R1-1]) & set(Q2[R2-1])
    if len(s) == 0:
        return 'Volunteer cheated!'
    if len(s) == 1:
        return s.pop()
    return 'Bad magician!'

def solve_large(case):
    return solve_small(case)

DEBUG = 'i'

from run import *
