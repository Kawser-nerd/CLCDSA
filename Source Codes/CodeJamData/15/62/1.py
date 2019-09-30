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


@memoize
def fac(n):
    if n == 0:
        return 1
    return fac(n-1) * n % mod

@memoize
def ifc(n):
    if n == 0: return 1
    return ifc(n-1) * inv(n) % mod

@memoize
def inv(n):
    if n <= 1:
        return 1
    return (mod - mod/n) * inv(mod%n) % mod

@memoize
def C(n,r):
    if r < 0 or r > n:
        return 0
    return fac(n) * ifc(r) * ifc(n-r) % mod

mod = 10**9 + 7

@memoize
def f(n):
    if n == 0:
        return 
    if n == 1:
        return 0
    return fac(n) * fac(n-1) % mod

@memoize
def g(n):
    if n == 0:
        return 1
    s = 0
    for k in xrange(1,n+1):
        s += C(n-1,k-1) * C(n,k) * f(k) * g(n-k)
        s %= mod
    return s

def answ(n,x):
    s = 0
    for h in xrange(x,n+1):
        s += C(n,h)**2 * fac(h) * g(n-h)
        s %= mod
    return s
z = input()
for cas in xrange(1,1+z):
    n, x =nums()
    ans = answ(n,x)
    #ans
    
    #print "Case #%s:" % cas
    print "Case #%s: %s" % (cas, ans)
