
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
    (H, W, D) = read_ints(f)
    M = []
    for i in range(H):
        M.append(read_word(f))
    return (H, W, D, M)

def write_case(f, i, res):
    f.write('Case #%d: '%(i+1))
    f.write('%s'%res)
    f.write('\n')

FAIL = 'NO SOLUTION'

INF = float('inf')
EPSILON = 1e-6

def sign(d):
    if d > 0:
        return 1
    if d < 0:
        return -1
    return 0

def frac(x):
    return x-math.floor(x)

def rnd(x):
    if frac(x) < 1-EPSILON:
        return int(x)
    return int(x)+1

def isint(x):
    f = frac(x)
    return f < EPSILON or 1-f < EPSILON

def dir_frac(x, dx):
    if dx == 0:
        return INF
    if isint(x):
        return 1
    if dx < 0:
        return frac(x)
    if dx > 0:
        return 1-frac(x)

def trace(D, M, myx, myy, dx, dy):
    res = 0
    x = myx
    y = myy
    while True:
        if abs(x-myx) < 1 and abs(y-myy) < 1:
            fx = dir_frac(2*x, dx)/2
            fy = dir_frac(2*y, dy)/2
        else:
            fx = dir_frac(x, dx)
            fy = dir_frac(y, dy)
        tx = fx/abs(dx) if dx != 0 else INF
        ty = fy/abs(dy) if dy != 0 else INF
        t = min(tx, ty)
        x += t*dx
        y += t*dy
        D -= t * (dx**2 + dy**2)**.5
        if D < -EPSILON:
            pout('"FOGGED"')
            break
        if not (isint(x) or isint(y)):
            if abs(x-myx) < EPSILON and abs(y-myy) < EPSILON:
                pout('"BINGO!"')
                res += 1
                break
            continue
        s = abs(sign(dx)-sign(dy))
        if isint(x) and isint(y):
            (cdx, cdy) = M.get((rnd(x), rnd(y), s), (1, 1))
        else:
            (cdx, cdy) = M.get((rnd(x), rnd(y), 'x' if isint(x) else 'y'), (1, 1))
        dx *= cdx
        dy *= cdy
        if dx == 0 and dy == 0:
            pout('"CORNER"')
            break
    return res

def gcd(a, b):
    while b:      
        (a, b) = (b, a%b)
    return a

def solve_small(case):
    (H, W, D, M) = case
    myx = [x for x in range(H) if 'X' in M[x]][0]
    myy = M[myx].index('X')
    M[myx] = M[myx][:myy] + '.' + M[myx][myy+1:]
    myx += 0.5
    myy += 0.5
    m = {}
    for x in range(1, H):
        for y in range(1, W):
            pat = M[x-1][y-1:y+1]+M[x][y-1:y+1]
            ABSORBE = (0, 0)
            REV_X = (-1, 1)
            REV_Y = (1, -1)
            REV = (-1, -1)
            if pat == '....':
                continue
            if pat == '...#':
                m[(x, y, 0)] = ABSORBE
                m[(x, y, 'x')] = REV_X
                m[(x, y, 'y')] = REV_Y
            if pat == '..#.':
                m[(x, y, 2)] = ABSORBE
                m[(x, y, 'y')] = REV_Y
            if pat == '..##':
                m[(x, y, 0)] = REV_X
                m[(x, y, 2)] = REV_X
                m[(x, y, 'x')] = REV_X
            if pat == '.#..':
                m[(x, y, 2)] = ABSORBE
                m[(x, y, 'x')] = REV_X
            if pat == '.#.#':
                m[(x, y, 0)] = REV_Y
                m[(x, y, 2)] = REV_Y
                m[(x, y, 'y')] = REV_Y
            if pat == '.##.':
                m[(x, y, 'x')] = REV_X
                m[(x, y, 'y')] = REV_Y
            if pat == '.###':
                m[(x, y, 0)] = REV
            if pat == '#...':
                m[(x, y, 0)] = ABSORBE
            if pat == '#..#':
                m[(x, y, 'x')] = REV_X
                m[(x, y, 'y')] = REV_Y
            if pat == '#.#.':
                m[(x, y, 0)] = REV_Y
                m[(x, y, 2)] = REV_Y
                m[(x, y, 'y')] = REV_Y
            if pat == '#.##':
                m[(x, y, 2)] = REV
                m[(x, y, 'x')] = REV_X
            if pat == '##..':
                m[(x, y, 0)] = REV_X
                m[(x, y, 2)] = REV_X
                m[(x, y, 'x')] = REV_X
            if pat == '##.#':
                m[(x, y, 2)] = REV
                m[(x, y, 'x')] = REV_X
                m[(x, y, 'y')] = REV_Y
            if pat == '###.':
                m[(x, y, 0)] = REV
                m[(x, y, 'x')] = REV_X
                m[(x, y, 'y')] = REV_Y
            if pat == '####':
                continue
    res = 0
    for dx in range(1, D+1):
        for dy in range(1 if dx > 1 else 0, dx if dx > 1 else 2):
            if gcd(dx, dy) != 1:
                continue
            if dx**2+dy**2 > D**2:
                continue
            res += trace(D, m, myx, myy, dx, dy)
            res += trace(D, m, myx, myy, -dx, dy)
            if dy:
                res += trace(D, m, myx, myy, dx, -dy)
                res += trace(D, m, myx, myy, -dx, -dy)
            if dy < dx:
                res += trace(D, m, myx, myy, dy, dx)
                res += trace(D, m, myx, myy, dy, -dx)
                if dy:
                    res += trace(D, m, myx, myy, -dy, dx)
                    res += trace(D, m, myx, myy, -dy, -dx)
    return res

solve_large = solve_small

##perr = pout
pout = lambda s: None
##pout = perr
