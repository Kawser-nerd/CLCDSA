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
    r, c = parts()
    grid = [list(raw_input()) for i in xrange(r)]
    def fillrow(row):
        found = None
        for i in range(c) + range(c-1,-1,-1):
            if row[i] == '?':
                if found: row[i] = found
            else:
                found = row[i]
    def fill():
        found = None
        for i in range(r) + range(r-1,-1,-1):
            if set(grid[i]) <= {'?'}:
                if found: grid[i] = found
            else:
                fillrow(grid[i])
                found = grid[i]

    fill()
    print "Case #%s:" % cas
    for row in grid:
        print ''.join(row)



