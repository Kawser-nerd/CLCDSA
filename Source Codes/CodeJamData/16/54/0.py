if 1:
    from sys import *
    from functools import *
    from collections import *
    from itertools import *
    from functools import *
    from heapq import *
    xr = xrange

    def print_args(*args, **kwargs):
        return ','.join(value for value in [','.join(map(repr, args)),','.join("%s=%s" % (k, repr(v)) for k, v in kwargs.items())] if value)

    def print_result(before=False, after=True):
        def fc(func):
            @wraps(func)
            def f(*args, **kwargs):
                if before:
                    print "%s(%s)"      % (func.__name__, print_args(*args, **kwargs))
                r = func(*args, **kwargs)
                if after:
                    print "%s(%s) = %s" % (func.__name__, print_args(*args, **kwargs), r)
                return r
            return f
        return fc

    def memoize(function):
        memo = {}
        @wraps(function)
        def f(*args):
            key = args
            if key not in memo:
                memo[key] = function(*args)
                if not (len(memo) & 32767):
                    print >>stderr, "memo", function.__name__, len(memo)
            return memo[key]
        f.memo = memo
        return f

    def line():
        return raw_input().strip()

    def parts(f=int):
        return map(f, line().split())

    def qparts(f=int):
        data = line().split()
        return data[0], map(f, data[1:])

def wala(l, r):
    for s in product('01', repeat=l):
        s = ''.join(s)
        if s not in r:
            return s
    assert False

def wilfred(w):
    return '1?' + term(w)

def torm(bits,w):
    if bits == 2:
        return 0
    if w < 2**(bits-2):
        return 1 + torm(bits-1,w)
    else:
        return torm(bits-1,w^((1<<bits-1)-1))

def walfrud(w):
    k = torm(len(w),int(w,2)) + len(w) - 1
    return ('01'*(k/2+1))[:k]

def term(w):
    if len(w) == 1:
        return ''
    if w[0] == w[1]:
        return str(int(w[0]) ^ 1) + '?' + term(w[1:])
    else:
        return '?' + term(w[1:])

def compute(w):
    if w[0] == '1':
        a, b = _compute(flip(w))
        a = flip(a)
        b = flip(b)
    else:
        a, b = _compute(w)
    return a, b

def _compute(w):
    assert w[0] == '0'
    if len(w) == 1:
        return '1', '1?'
    a = walfrud(w)
    b = wilfred(w)
    return a, b

def flip(x):
    return ''.join(fl(c) for c in x)

def fl(c):
    if c == '0': return '1'
    if c == '1': return '0'
    return c

# from memoize import *
# @memoize
def sset(a,b,v='0'):
    if not a and not b:
        return set([''])
    vals = set()
    if a:
        if a[0] == '?':
            vals |= set(v + s for s in sset(a[1:],b,v=v))
        else:
            vals |= sset(a[1:],b,v=a[0])
    if b:
        if b[0] == '?':
            vals |= set(v + s for s in sset(a,b[1:],v=v))
        else:
            vals |= sset(a,b[1:],v=b[0])
    return vals


for cas in xrange(1,1+input()):
    n, l = parts()
    goods = set(parts(str))
    wala = line()

    if wala in goods:
        ans = 'IMPOSSIBLE'
    else:
        a, b = compute(wala)
        # ss = sset(a,b)
        # assert wala not in ss
        # assert len(ss) == (1<<len(wala))-1

        ans = a + ' ' + b
    
    #print "Case #%s:" % cas
    print "Case #%s: %s" % (cas, ans)
