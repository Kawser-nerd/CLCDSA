
import math
import itertools
import numpy as np

import devtools

################################################################################

# primes(n) = primes up to n
def primes(n):
    if n < 2:
        return []
    s = np.arange(3, n+1, 2)
    root = n**.5
    for x in s:
        if not x:
            continue
        if x > root:
            break
        s[(x**2-3)//2::x] = 0
    return [2] + list(filter(None, s))

PRIMES = primes(2**16)

def fact(x):
    root = math.floor(x**.5)
    for i in PRIMES:
        if x%i == 0:
            return i
        if i > root:
            return

def read_case(f):
    return read_ints(f)

def solve_small(case):
    N, J = case
    s = '1' + '0'*(N-2) + '1'
    res = []
    while len(res) < J:
        f = [fact(int(s, b)) for b in range(2, 11)]
        if None not in f:
            res.append([int(s, 10)] + f)
        s = bin(int(s, 2) + 2)[2:]
    return res

def solve_large(case):
    return solve_small(case)

def write_case(f, i, res):
    f.write('Case #%d:\n'%i)
    for r in res:
        f.write('%s\n'%' '.join(str(x) for x in r))
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
