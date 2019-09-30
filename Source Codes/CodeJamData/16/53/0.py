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

from math import *

def mag((a, b, c)):
    return hypot(hypot(a, b), c)

def sub((a, b, c), (d, e, f)):
    return a - d, b - e, c - f

def good(pts,d):
    n = len(pts)
    reach = [0]
    vis = [False]*n
    vis[0] = True
    f = 0
    while f < len(reach):
        i = reach[f]; f += 1
        for j in xrange(n):
            if not vis[j] and mag(sub(pts[i], pts[j])) <= d:
                vis[j] = True
                reach.append(j)
                if j == 1:
                    return True

    return False

for cas in xrange(1,1+input()):
    ans = 0
    n, s = parts()
    pts = []
    for i in xrange(n):
        x, y, z, vx, vy, vz = parts()
        p = x, y, z
        v = vx, vy, vz
        assert v == (0, 0, 0)
        pts.append(p)

    L = 0.0
    R = 100000.0
    while R - L > 1e-4:
        M = (L + R) * 0.5
        if good(pts,M):
            R = M
        else:
            L = M

    ans = R

    #print "Case #%s:" % cas
    print "Case #%s: %.11f" % (cas, ans)
