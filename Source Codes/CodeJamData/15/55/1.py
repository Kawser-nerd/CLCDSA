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

def f(D, d):
    if D == 0:
        return 0
    v = [0]*(2*D)
    w = [d[i+D] - d[i] for i in xrange(D)]
    # print w
    cum = [0]*(2*D+1)
    v[0] = -(w[D-1] + w[0]) >> 1
    for i in xrange(1,D):
        v[i] = w[i-1] - w[i] >> 1
    # print v
    for i in xrange(D):
        if v[i] < 0:
            v[i+D] = -v[i]
            v[i] = 0
    # print v
    for i in xrange(2*D):
        cum[i] -= v[i]
        cum[(i+D) % (2*D)] += v[i]
        if i+D >= 2*D:
            cum[2*D] += v[i]
    for i in xrange(2*D,0,-1):
        cum[i-1] += cum[i]
    # print cum
    for i in xrange(2*D):
        d[i] -= cum[i+1]
        if d[i] < 0:
            return None
    for i in xrange(D):
        assert d[i] == d[i+D]
    res = f(D>>1, d[:D])
    if res is not None:
        res += sum(v)
    return res


def solve():
    N, D = map(int, raw_input().strip().split())
    d = map(int, raw_input().strip().split())
    # 2D <= N
    for i in xrange(2*D,N):
        if d[i] != d[i-2*D]:
            return None

    d = d[:2*D]
    return f(D, d)




z = input()
for cas in xrange(1,z+1):
    # a = solve()
    ans = solve()
    if ans is None:
        ans = 'CHEATERS!'
    
    #print "Case #%s:" % cas
    print "Case #%s: %s" % (cas, ans)
