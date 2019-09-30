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

INF = 10**100
def f(hd, ad, hk, ak, b, d, D, B):
    L = 1000
    h = hd
    ct = 0
    while ct <= L and hk > 0:
        ct += 1
        if ak - (d if D else 0) >= h and (D or B or hk > ad):
            h = hd
        elif D:
            D -= 1
            ak -= d
        elif B:
            B -= 1
            ad += b
        else:
            hk -= ad
        h -= ak
    return ct if ct <= L else INF

def solve(hd, ad, hk, ak, b, d):
    bestf = INF
    for D in xrange(1 if d == 0 else ak / d + 11):
        for B in xrange(1 if b == 0 else hk / b + 11):
            currf = f(hd, ad, hk, ak, b, d, D, B)
            if bestf > currf:
                bestf = currf
    return bestf if bestf < INF else 'IMPOSSIBLE'

for cas in xrange(1,1+input()):
    hd, ad, hk, ak, b, d = parts()
    ans = solve(hd, ad, hk, ak, b, d)
    
    #print "Case #%s:" % cas
    print "Case #%s: %s" % (cas, ans)
