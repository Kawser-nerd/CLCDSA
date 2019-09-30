
import math
import itertools
import numpy as np

import devtools

################################################################################

def read_case(f):
    N = read_int(f)
    F = read_ints(f)
    return N, F

def solve_small(case):
    N, F = case
    D = dict(zip(itertools.count(1), F))
    res = []
    for i in range(1, N+1):
        d = D.copy()
        r = [i]
        while r[-1] in d:
            r.append(d.pop(r[-1]))
        res.append(r)
    best_loop = set()
    for i in range(len(res)):
        if res[i][0] == res[i][-1]:
            loop = set(res[i])
            if len(loop) > len(best_loop):
                best_loop = loop
    chosen = set()
    while True:
        best = set()
        for i in range(len(res)):
            for j in range(i+1, len(res)):
                if res[i][-1] == res[j][-2] and res[i][-2] == res[j][-1]:
                    chain = set(res[i]) | set(res[j])
                    if len(chain) > len(best):
                        best = chain
        if best:
            chosen |= best
            res = [r for r in res if not (set(r) & best)]
        else:
            break
    return max(len(chosen), len(best_loop))

def solve_large(case):
    return solve_small(case)

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

from run import *
