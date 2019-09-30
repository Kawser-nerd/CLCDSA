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


for cas in xrange(1,1+input()):
    ans = 0

    n = input()
    a = [map(int, raw_input()) for i in xrange(n)]
    vis = [False]*(2*n)
    comps = []
    for i in xrange(n):
        if vis[i]: continue
        queue = [i]
        vis[i] = True
        f = 0
        while f < len(queue):
            i = queue[f]; f += 1
            if i < n:
                for j in xrange(n,2*n):
                    if a[i][j-n]:
                        if not vis[j]:
                            vis[j] = True
                            queue.append(j)
            else:
                for j in xrange(n):
                    if a[j][i-n]:
                        if not vis[j]:
                            vis[j] = True
                            queue.append(j)

        low = [v for v in queue if v < n]
        hgh = [v for v in queue if v >= n]
        for i in low:
            for j in hgh:
                if not a[i][j-n]:
                    ans += 1
        low = len(low)
        hgh = len(hgh)
        if low != hgh:
            comps.append((low, hgh))
    badlow = sum(not vis[i] for i in xrange(n))
    badhgh = sum(not vis[i] for i in xrange(n,2*n))
    while badlow and badhgh:
        badlow -= 1
        badhgh -= 1
        ans += 1

    def subsets(mask):
        s = 0
        while True:
            yield s
            s = s - 1 & mask
            if not s: break

    @memoize
    def totals(mask):
        if not mask:
            return 0, 0, 0
        i = 0
        while (mask & (1<<i)) == 0: i += 1
        mask ^= 1<<i
        l1, h1, m1 = totals(mask)
        l2, h2 = comps[i]
        m2 = l2*h2
        return l1 + l2, h1 + h2, m1 + m2

    @memoize
    def best(mask, low, hgh):
        if not mask:
            return 0
        i = 0
        while (mask & (1<<i)) == 0: i += 1
        mask ^= 1<<i
        res = 10**100
        for s in subsets(mask):
            tlow, thgh, tmern = totals(s | (1<<i))
            if tlow <= thgh:
                if thgh - tlow <= low:
                    res = min(res, thgh**2 - tmern + best(mask ^ s, low - (thgh - tlow), hgh))
            else:
                assert thgh <= tlow
                if tlow - thgh <= hgh:
                    res = min(res, tlow**2 - tmern + best(mask ^ s, low, hgh - (tlow - thgh)))
        return res

    ans += best((1<<len(comps))-1, badlow, badhgh)

    #print "Case #%s:" % cas
    print "Case #%s: %s" % (cas, ans)
