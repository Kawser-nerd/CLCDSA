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

def add((a, b), (c, d)):
    return a + c, b + d

def sub((a, b), (c, d)):
    return a - c, b - d

#(-1, 0) -> (0, 1)
def rot90((a, b)):
    return b, -a
def rot270((a, b)):
    return -b, a

refl = {}
def pairr(c, a, b):
    refl[c, a] = b
    refl[c, b] = a
pairr('/', (-1,0), (0,1))
pairr('/', (1,0), (0,-1))
pairr('\\', (-1,0), (0,-1))
pairr('\\', (1,0), (0,1))

def ndir(c, (i,j)):
    assert (i,j) in [(-1,0),(0,1),(1,0),(0,-1)]
    assert c in ['\\', '/']
    return refl[c, (i,j)]

for cas in xrange(1,1+input()):
    print "Case #%s:" % cas
    ans = 0
    r, c = parts()
    vals = parts()
    pairs = []
    pair = {}
    for i in xrange(0,len(vals),2):
        a,b = vals[i:i+2]
        a -= 1
        b -= 1
        pairs.append((a,b))
        pair[a] = b
        pair[b] = a

    grid = [['/']*c for i in xrange(r)]

    def finder((i,j),p):
        # print 'now at', (i,j), 'from', p
        if 0 <= i < r and 0 <= j < c:
            ni,nj = add((i,j), ndir(grid[i][j],sub((i,j),p)))
            return finder((ni,nj),(i,j))
        else:
            # print 'done!'
            return i, j

    def rindex((i,j)):
        if i == -1:
            assert 0 <= j < c
            return j
        if j == c:
            assert 0 <= i < r
            return c + i
        if i == r:
            assert 0 <= j < c
            return c + r + c - 1 - j
        if j == -1:
            assert 0 <= i < r
            return c + r + c + r - 1 - i
        assert False

    def find(i):
        if i < c:
            return rindex(finder((0,i), (-1,i)))
        i -= c
        if i < r:
            return rindex(finder((i,c-1), (i,c)))
        i -= r
        if i < c:
            return rindex(finder((r-1,c-1-i), (r,c-1-i)))
        i -= c
        if i < r:
            return rindex(finder((r-1-i,0), (r-1-i,-1)))
        i -= r
        assert False





    # print '-'*50
    for mask in xrange(1<<r*c):
        # print
        # print
        # print
        for i in xrange(r):
            for j in xrange(c):
                if mask & 1:
                    grid[i][j] = '\\'
                else:
                    grid[i][j] = '/'
                mask >>= 1

        # print 'trying grid'
        # for row in grid:
        #     print ''.join(row)

        for a, b in pairs:
            # print 'finding', a, 'for', b
            fa = find(a)
            # print 'got', fa
            if fa != b:
                break
        else:
            for row in grid:
                print ''.join(row)
            break
    else:
        print 'IMPOSSIBLE'

    
    #print "Case #%s: %s" % (cas, ans)
