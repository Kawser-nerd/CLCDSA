
import itertools
import math
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
    ab = read_arr(f, N)
    return (N, ab)

def write_case(f, i, res):
    f.write('Case #%d: '%i)
    f.write('%s'%res)
    f.write('\n')

################################################################################

FAIL = 'Too Bad'

def solve_small(case):
    (N, ab) = case
    b = []
    E = 0
    res = 0
    while True:
        change = True
        while change:
            lab = len(ab)
            lb = len(b)
            ab = [(a, b) for (a, b) in ab if b > E]
            E += 2*(lab-len(ab))
            b = [x for x in b if x > E]
            E += lb-len(b)
            change = len(ab) != lab or len(b) != lb
        if not ab and not b:
            return res+N
        opt = sorted([(ab[i][1], i) for i in range(len(ab)) if ab[i][0] <= E])
        if not opt:
            return FAIL
        b.append(opt[-1][0])
        ab = ab[:opt[-1][1]]+ab[opt[-1][1]+1:]
        E += 1
        res += 1

solve_large = solve_small

##def solve_large(case):

##DEBUG = 'i'

from run import *
