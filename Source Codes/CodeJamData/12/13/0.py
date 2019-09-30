
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
    Cs = []
    for i in range(N):
        (C, S, P) = read_words(f)
        Cs.append((C, int(S), int(P)))
    return (N, Cs)

def write_case(f, i, res):
    f.write('Case #%d: '%i)
    f.write('%s'%res)
    f.write('\n')

################################################################################

INF = float('inf')

import heapq

def solve_small(case):
    (N, Cs) = case
    col = []
    for i in range(N):
        (c1, s1, p1) = Cs[i]
        for j in range(i+1, N):
            (c2, s2, p2) = Cs[j]
            if s1 == s2:
                if abs(p1-p2) < 5:
                    heapq.heappush(col, (-1, True, i, j))
                continue
            t1 = (p2-p1+5)/(s1-s2)
            t2 = (p2-p1-5)/(s1-s2)
            if t1 > t2:
                (t1, t2) = (t2, t1)
            if t2 < 0:
                continue
            if t1 < 0:
                t1 = -1
            heapq.heappush(col, (t1, True, i, j))
            heapq.heappush(col, (t2, False, i, j))
    l = [None] * N
    act = []
    for i in range(N):
        act.append(set())
    cnt = 0
    while col:
        (t, c, i, j) = heapq.heappop(col)
        if c:
            act[i].add(j)
            act[j].add(i)
        else:
            act[i].remove(j)
            act[j].remove(i)
        if t == -1:
            l[i] = Cs[i][0] == 'L'
            l[j] = Cs[j][0] == 'L'
            continue
        if c:
            if l[i] is None:
                if l[j] is None:
                    l[i] = (cnt, True)
                    l[j] = (cnt, False)
                    cnt += 1
                elif l[j] is True:
                    l[i] = False
                elif l[j] is False:
                    l[i] = True
                else:
                    (k, b) = l[j]
                    l[i] = (k, not b)
            elif l[i] is True:
                if l[j] is None:
                    l[j] = False
                elif l[j] is True:
                    return t
                elif l[j] is False:
                    pass
                else:
                    (k, b) = l[j]
                    for x in range(N):
                        if isinstance(l[x], tuple) and l[x][0] == k:
                            l[x] = b != l[x][1]
            elif l[i] is False:
                if l[j] is None:
                    l[j] = True
                elif l[j] is True:
                    pass
                elif l[j] is False:
                    return t
                else:
                    (k, b) = l[j]
                    for x in range(N):
                        if isinstance(l[x], tuple) and l[x][0] == k:
                            l[x] = b == l[x][1]
            else:
                (k, b) = l[i]
                if l[j] is None:
                    l[j] = (k, not b)
                elif l[j] is True:
                    for x in range(N):
                        if isinstance(l[x], tuple) and l[x][0] == k:
                            l[x] = b != l[x][1]
                elif l[j] is False:
                    for x in range(N):
                        if isinstance(l[x], tuple) and l[x][0] == k:
                            l[x] = b == l[x][1]
                else:
                    (k_, b_) = l[j]
                    if k == k_:
                        if b == b_:
                            return t
                        else:
                            continue
                    for x in range(N):
                        if isinstance(l[x], tuple) and l[x][0] == k:
                            l[x] = (k_, not b ^ b_ ^ l[x][1])
        else: #end col
            if not act[i]:
                l[i] = None
            if not act[j]:
                l[j] = None
    return 'Possible'

solve_large = solve_small

##def solve_large(case):

DEBUG = 'i'

from run import *
