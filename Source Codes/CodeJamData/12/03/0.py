
import sys
import os
import itertools
import math
import numpy

__file__ = sys.argv[0]
__path__ = os.path.dirname(__file__)
__prob__ = os.path.basename(__path__)

def pout(s, back=0):
    f = sys._getframe(back+1)
    d = 0
    if 'depth' in f.f_locals:
        d = f.f_locals['depth']
    print(' '*d + s + ' = ' + repr(eval(s, f.f_globals, f.f_locals)))

def perr(s, back=0):
    f = sys._getframe(back+1)
    d = 0
    if 'depth' in f.f_locals:
        d = f.f_locals['depth']
    ERR_FILE.write(' '*d + '%s = %s\n'%(s, repr(eval(s, f.f_globals, f.f_locals))))

def argmin(f, s=None):
    a = f
    if s is None:
        s = range(len(a))
        f = lambda i: a[i]
    res = None
    for x in s:
        y = f(x)
        if res is None or best > y:
            best = y
            res = x
    return res

def argmax(f, s=None):
    a = f
    if s is None:
        s = range(len(a))
        f = lambda i: a[i]
    res = None
    for x in s:
        y = f(x)
        if res is None or best < y:
            best = y
            res = x
    return res

def read_word(f):
    return next(f).strip()

def read_int(f, b=10):
    return int(read_word(f), b)

def read_words(f, d=' '):
    return read_word(f).split(d)

def read_ints(f, b=10, d=' '):
    return [int(x, b) for x in read_words(f, d)]

def read_word_arr(f, R):
    res = []
    for i in range(R):
        res.append(read_word(f))
    return res

def read_ints_arr(f, R, dtype=int, *args, **kwargs):
    res = []
    for i in range(R):
        res.append(read_ints(f, *args, **kwargs))
    return numpy.array(res, dtype)

def solve(solver, fn, start_case=0, end_case=None, out_fn=None):
    global ERR_FILE
    in_fn = fn + '.in'
    if out_fn is None:
        out_fn = fn + '.out'
    err_fn = fn + '.err'
    if start_case == 0:
        append = True
        if os.path.exists(out_fn):
            with open(out_fn, 'r') as f:
                for l in f:
                    if l[:6] == 'Case #':
                        start_case = int(l[6:l.index(':')])+1
    else:
        append = False
    with open(in_fn, 'r') as fi:
        with open(out_fn, 'a' if append else 'w') as fo:
            with open(err_fn, 'w') as ERR_FILE:
                T = read_int(fi)
                for i in range(T):
                    case = read_case(fi)
                    if i+1 < start_case:
                        continue
                    print('Case #%d of %d'%(i+1, T))
                    ERR_FILE.write('Case #%d of %d\n'%(i+1, T))
                    perr('case')
                    res = solver(case)
                    perr('res')
                    write_case(fo, i, res)
                    fo.flush()
                    if end_case is not None and i+1 == end_case:
                        break

def test(start_case=1, end_case=None):
    fn = os.path.join(__path__, 'test')
    solve(solve_small, fn, start_case, end_case)

def small(start_case=1, end_case=None):
    fn = os.path.join(__path__, '%s-small-attempt0'%__prob__)
    solve(solve_small, fn, start_case, end_case)

def small2(start_case=1, end_case=None):
    fn = os.path.join(__path__, '%s-small-attempt0'%__prob__)
    solve(solve_large, fn, start_case, end_case, fn + '2.out')

def large(start_case=0, end_case=None):
    fn = os.path.join(__path__, '%s-large'%__prob__)
    solve(solve_large, fn, start_case, end_case)

################################################################################

def read_case(f):
    (A, B) = read_ints(f)
    return (A, B)

def write_case(f, i, res):
    f.write('Case #%d: '%(i+1))
    f.write('%s'%res)
    f.write('\n')

FAIL = 'NO SOLUTION'

def aux(n, a, b):
    res = 0
    s = set()
    for i in range(1, len(n)):
        m = n[i:]+n[:i]
        if m > n and m >= a and m <= b and m not in s:
            res += 1
            s.add(m)
    return res

def solve_small(case):
    (A, B) = case
    a = str(A)
    b = str(B)
    res = 0
    for n in range(A, B+1):
        res += aux(str(n), a, b)
    return res

solve_large = solve_small

##perr = pout
##pout = lambda s: None
pout = perr
