
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
    B = read_arr(f, 4, read_letters)
    read_word(f)
    return B

def write_case(f, i, res):
    f.write('Case #%d: '%i)
    f.write('%s'%res)
    f.write('\n')

################################################################################

def test(a):
    if '.' not in a and 'O' not in a:
        return 'X won'
    if '.' not in a and 'X' not in a:
        return 'O won'

def solve_small(case):
    draw = True
    for row in case:
        if '.' in row:
            draw = False
        res = test(row)
        if res:
            return res
    for i in range(len(case[0])):
        col = [row[i] for row in case]
        res = test(col)
        if res:
            return res
    diag = [case[i][i] for i in range(len(case))]
    res = test(diag)
    if res:
        return res
    diag = [case[i][-i-1] for i in range(len(case))]
    res = test(diag)
    if res:
        return res
    if draw:
        return 'Draw'
    return 'Game has not completed'

def solve_large(case):
    return solve_small(case)

DEBUG = 'i'

from run import *
