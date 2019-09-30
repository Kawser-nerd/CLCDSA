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
from fractions import *
from decimal import Decimal as D, getcontext
xr = xrange


def init():
    pass

def solve():
    n, f = line().split()
    n = int(n)
    f = Fraction(f)
    s = line()
    i = 0
    d = 10**9
    for I in xrange(n):
        tl = 0
        ct = 0
        df = 10**9
        for J in xrange(I,n):
            tl += s[J] == '1'
            ct += 1
            df = min(df, abs(Fraction(tl, ct) - f))
        if d > df:
            d = df
            i = I

    return i


init()
z = input()
for cas in xrange(1,1+z):
    ans = solve()
    
    #print "Case #%s:" % cas
    print "Case #%s: %s" % (cas, ans)
