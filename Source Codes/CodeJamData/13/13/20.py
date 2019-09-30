
import math
import itertools
from collections import Counter
import random
import functools
import operator
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
    [R, N, M, K] = read_ints(f)
    P = read_arr(f, R)
    return [R, N, M, K, P]

def write_case(f, i, res):
    f.write('Case #%d:\n'%i)
    f.write('%s'%res)
    f.write('\n')

################################################################################

def sim(R, N, M, K, fn_in, fn_out):
    with open(fn_in, 'w') as f_in:
        with open(fn_out, 'w') as f_out:
            f_in.write('1\n')
            f_in.write('%d %d %d %d\n'%(R, N, M, K))
            f_out.write('Case #1:\n')
            for r in range(R):
                nums = sorted(random.choice(range(2, M+1)) for i in range(N))
                f_out.write(''.join(str(x) for x in nums))
                f_out.write('\n')
                for k in range(K):
                    if k > 0:
                        f_in.write(' ')
                    trial = functools.reduce(operator.mul, (n for n in nums if random.random() < .5), 1)
                    f_in.write(str(trial))
                f_in.write('\n')

def aux_small(p):
    res = Counter()
    for f in [3, 5]:
        while True:
            if any(x%f == 0 for x in p):
                res.update([f])
                p = [x//f if (x%f == 0) else x for x in p]
            else:
                break
    if sum(res.values()) == 3:
        return res
    if sum(res.values()) == 2:
        res.update([max(2, max(p))])
        return res
    if sum(res.values()) == 1:
        if 16 in p:
            res.update([4, 4])
            return res
        if 8 in p:
            res.update([2, 4])
            return res
        res.update([2, 2])
        return res
    p = [int(math.log(x, 2)) for x in p]
    if all(x%2 == 0 for x in p):
        res.update([4, 4, 4])
        return res
    res.update([2])
    if max(p) <= 3:
        res.update([2, 2])
        return res
    if max(p) == 4:
        res.update([2, 4])
        return res
    if max(p) == 5:
        res.update([4, 4])
        return res

def solve_small(case):
    [R, N, M, K, P] = case
    res = []
    for p in P:
        r = aux_small(p)
        res.append(''.join(sorted(str(x) for x in r.elements())))
    return '\n'.join(res)

def solve_large(case):
    return solve_small(case)

DEBUG = 'i'

from run import *
