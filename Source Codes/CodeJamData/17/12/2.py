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


def bar(w, v):
    k = max(1, v / w)
    K = k + 1
    good = lambda k: k >= 1 and 9*k*w <= 10*v <= 11*k*w
    if good(k) or good(K):
        while good(k): k -= 1
        while good(K): K += 1
        k += 1
        K -= 1
        assert k <= K
        assert not good(k-1)
        assert good(k)
        assert good(K)
        assert not good(K+1)
        return k, K



for cas in xrange(1,1+input()):
    n, p = parts()
    ing = parts()
    assert len(ing) == n
    bars = [[] for i in xrange(n)]
    for i in xrange(n):
        vals = parts()
        assert len(vals) ==p
        for j in xrange(p):
            b = bar(ing[i], vals[j])
            if b:
                bars[i].append(b)
        bars[i].sort(reverse=True)
    ans = 0
    if n == 1:
        ans = len(bars[0])
    else:
        while all(bars):
            i = min(range(n), key=lambda i: bars[i][-1][1])
            I = max([I for I in xrange(n) if I != i], key=lambda I: bars[I][-1][0])
            if bars[I][-1][0] <= bars[i][-1][1]:
                ans += 1
                for ii in xrange(n):
                    bars[ii].pop()
            else:
                bars[i].pop()



    
    print "Case #%s: %s" % (cas, ans)

