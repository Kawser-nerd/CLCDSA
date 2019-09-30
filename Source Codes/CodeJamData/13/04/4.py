
import math
import itertools
from collections import Counter
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
    (K, N) = read_ints(f)
    H = read_ints(f)
    C = read_arr(f, N)
    return (K, N, H, C)

def write_case(f, i, res):
    f.write('Case #%d: '%i)
    f.write('%s'%res)
    f.write('\n')

################################################################################

def prepare_case(case):
    (K, N, H, C) = case
    m = 1
    if H:
        m = max(m, max(H))
    if C:
        m = max(m, max(c[1] for c in C))
    for c in C:
        if c[2:]:
            m = max(m, max(c[2:]))
    C = [(i+1, C[i][0], Counter(C[i][2:])) for i in range(len(C))]
    return (m, Counter(H), C)

def find_paths(m, C):
    paths = [[None for i in range(m+1)] for j in range(m+1)]
    change = True
    while change:
        change = False
        for i in range(len(C)):
            c = C[i]
            for k in c[2]:
                if paths[c[1]][k] is None:
                    paths[c[1]][k] = [i]
                    change = True
                for l in range(m+1):
                    if paths[k][l] is not None and paths[c[1]][l] is None:
                        paths[c[1]][l] = [i] + paths[k][l]
                        change = True
    return paths

def solvable(m, H, C):
    todo = C.copy()
    uses = set()
    makes = H.copy()
    while todo:
        change = False
        for i in range(len(todo)-1, -1, -1):
            c = todo[i]
            if c[1] in makes:
                uses.add(c[1])
                makes += c[2]
                makes -= Counter([c[1]])
                todo.pop(i)
                change = True
        if change:
            continue
        if not todo:
            return True
        paths = find_paths(m, todo)
        for k in uses:
            if paths[k][k] is not None:
                p = paths[k][k]
                for i in p:
                    uses.add(todo[i][1])
                makes += sum((todo[i][2] for i in p), Counter())
                makes -= Counter(todo[i][1] for i in p)
                for i in sorted(p, reverse=True):
                    todo.pop(i)
                break
        else:
            return False
    return True

def solve_small(case):
    (m, H, C) = prepare_case(case)
    if not solvable(m, H, C):
        return 'IMPOSSIBLE'
    res = []
    while C:
        for i in range(len(C)):
            if C[i][1] in H and solvable(m, H + C[i][2] - Counter([C[i][1]]), C[:i] + C[i+1:]):
                break
        else:
            return 'IMPOSSIBLE'
        res.append(C[i][0])
        H += C[i][2]
        H -= Counter([C[i][1]])
        C = C[:i] + C[i+1:]
    return ' '.join(map(str, res))

def solve_large(case):
    return solve_small(case)

DEBUG = 'f'

from run import *
