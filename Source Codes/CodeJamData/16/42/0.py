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


def prob(p,k):
    @memoize
    def f(i,k):
        if i == 0:
            return k == 0
        else:
            res = 0
            i -= 1
            if k > 0:
                res += p[i] * f(i,k-1)
            res += (1-p[i]) * f(i,k)
            return res

    return f(len(p),k)

for cas in xrange(1,1+input()):
    n, k = parts()
    p = parts(float)
    p.sort()
    ans = 0
    for i in xrange(n+1):
        for j in xrange(i,n+1):
            if i + n - j == k:
                ans = max(ans, prob(p[:i] + p[j:], k/2))
    
    #print "Case #%s:" % cas
    print "Case #%s: %.11f" % (cas, ans)
