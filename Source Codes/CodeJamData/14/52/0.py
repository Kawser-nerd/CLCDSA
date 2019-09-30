from functools import wraps
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
    def f(*args, **kwargs):
        key = args, tuple(sorted(kwargs.items()))
        if key not in memo:
            memo[key] = function(*args, **kwargs)
        return memo[key]
    f.memo = memo
    return f

def nums(t=int): return map(t, raw_input().strip().split())
from collections import *
from itertools import *
from functools import *
from heapq import *
xr = xrange


@memoize
#@print_result()
def f(i, mv):
    if i == n:
        return 0
    mve = (hs[i]+q-1)/q
    a1 = f(i+1, mv + mve)
    x = (hs[i]-1)%q/p+1
    m = (hs[i]-1)/q
    #assert m * q + x * p >= hs[i]
    #assert m * q + (x-1) * p < hs[i]
    #assert (m-1) * q + x * p < hs[i]
    if x-m <= mv:
        a2 = f(i+1, mv - (x-m)) + gs[i]
        a1 = max(a1, a2)
    return a1

z = input()
for cas in xrange(1,z+1):
    f.memo.clear()
    p, q, n = nums()
    hs = []
    gs = []
    for i in xrange(n):
        h, g = nums()
        hs.append(h)
        gs.append(g)
    #print hs
    #print gs
    ans = f(0,1)
    print "Case #%s: %s" % (cas, ans)
