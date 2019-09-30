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


        # 5 5 6
        # 2 3 3
        # 3 2 3

        # 10 11 11
        # 5 5 6
        # 5 6 5

def combine(a,b):
    if a < b:
        return a+b
    else:
        return b+a
    
def tourn(r,p,s):
    if r + p + s == 1:
        if r: return 'R'
        if p: return 'P'
        if s: return 'S'
    if p == s:
        return combine(tourn(r/2, p/2, s/2+1), tourn(r/2, p/2+1, s/2))
    if s == r:
        return combine(tourn(r/2+1, p/2, s/2), tourn(r/2, p/2, s/2+1))
    if r == p:
        return combine(tourn(r/2, p/2+1, s/2), tourn(r/2+1, p/2, s/2))
    assert False

for cas in xrange(1,1+input()):
    n,r,p,s = parts()
    
    print "Case #%s:" % cas,
    if max(r,p,s) - min(r,p,s) > 1:
        print 'IMPOSSIBLE'
    else:
        print tourn(r,p,s)

    #print "Case #%s: %s" % (cas, ans)
