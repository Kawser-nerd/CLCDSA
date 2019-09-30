
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
    [E, R, N] = read_ints(f)
    V = read_ints(f)
    return [E, R, N, V]

def write_case(f, i, res):
    f.write('Case #%d: '%i)
    f.write('%d'%res)
    f.write('\n')

################################################################################

def aux(E, R, V, s, t):
    if not V:
        return (0, [])
    v = max(V)
    i = V.index(v)
    surplus = min(s + i*R, E) - max(t - (len(V)-i)*R, 0)
    (a, ar) = aux(E, R, V[:i], s, min(s + i*R, E))
    (b, br) = aux(E, R, V[i+1:], max(t - (len(V)-i)*R, 0) + R, t)
    return (a + v*surplus + b, ar + [surplus] + br)

def solve_small(case):
    [E, R, N, V] = case
    (a, ar) = aux(E, R, V, E, R)
##    dbg('ar')
    return a

def solve_large(case):
    return solve_small(case)

DEBUG = 'i'

from run import *
