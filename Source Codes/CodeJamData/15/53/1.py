from sys import *
from functools import *

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
    return map(f, line().split(" "))

def qparts(f=int):
    data = line().split(" ")
    return data[0], map(f, data[1:])

nums = parts
from collections import *
from itertools import *
from functools import *
from heapq import *
xr = xrange


def subok(y, n, left, ps, es, mask, T, P):
    if mask == (1<<n)-1:
        return T
    fd = -1
    tm = 1e111
    sp = -y if left else y
    for i in xrange(n):
        if mask & (1<<i): continue
        if left and ps[i] > 0 or not left and ps[i] < 0: continue
        # ps[i] + es[i]*(T + t) = P + sp * t
        t = (ps[i] + es[i] * T - P) / (sp - es[i])
        if tm > t or abs(tm - t) <= 1e-11 and abs(es[i]) > abs(es[fd]):
            fd = i
            tm = t
    if fd == -1:
        return 1e111

    mask |= 1 << fd
    return min(subok(y, n, False, ps, es, mask, T + tm, P + sp * tm),
        subok(y, n, True, ps, es, mask, T + tm, P + sp * tm),)




def solve():
    y, n = line().split()
    y = float(y)
    n = int(n)
    ps = parts(float)
    es = parts(float)
    for i in xrange(n):
        if ps[i] < 0:
            es[i] = -es[i]
    return min(subok(y, n, False, ps, es, 0, 0.0, 0.0), subok(y, n, True, ps, es, 0, 0.0, 0.0))

z = input()
for cas in xrange(1,z+1):

    ans = solve()
    
    #print "Case #%s:" % cas
    print "Case #%s: %.11lf" % (cas, ans)
