from functools import wraps
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
    def f(*args, **kwargs):
        key = args, tuple(sorted(kwargs.items()))
        if key not in memo:
            memo[key] = function(*args, **kwargs)
        return memo[key]
    f.memo = memo
    return f

def nums(t=int): return map(t, raw_input().strip().split())
from collections import *
from itertools import *
from functools import *
from heapq import *
xr = xrange

z = input()
for cas in xrange(1,z+1):
    n = input()
    ts = []#[None]*n
    vs = []#[None]*n
    vset = set()
    for i in xrange(n):
        t, v = raw_input().strip().split()
        v = int(v)
        ts.append(t)
        vs.append(v)
        if v > 0: vset.add(v)

    range_reqs = []
    for v in vset:
        i = 0
        while vs[i] != v:
            i += 1
        ch = ts[i]
        p = i

        for i in xrange(i+1,n):
            if vs[i] == v:
                if ch == ts[i]:
                    range_reqs.append((p, i, v, ('E' if ch == 'L' else 'L')))
                else:
                    ch = ts[i]
                p = i

    #print ' '.join(ts)
    #print ' '.join(map(str, vs))
    #print

    bad = False
    # assign range_reqs
    range_reqs.sort()
    #print "got range_reqs", range_reqs
    ri = 0
    needs_E = []
    needs_L = []
    for i in xrange(n):
        while ri < len(range_reqs) and range_reqs[ri][0] == i:
            I, J, V, C = range_reqs[ri]
            ri += 1
            # add to list
            if C == 'E':
                needs_E.append((J, V))
            else:
                needs_L.append((J, V))
        
        if vs[i] > 0: continue
        if ts[i] == 'E':
            needs = needs_E
        else:
            needs = needs_L


        if needs:
            ix = 0
            for ii in xrange(1,len(needs)):
                if needs[ix][0] > needs[ii][0]:
                    ix = ii
            if needs[ix][0] < i:
                bad = True
                break
            vs[i] = needs[ix][1]
            needs = needs[:ix] + needs[ix+1:]
            if ts[i] == 'E':
                needs_E = needs
            else:
                needs_L = needs

    #print ' '.join(ts)
    #print ' '.join(map(str, vs))
    #print

    if needs_L or needs_E:
        bad = True
    else:
        ext = 0
        for v in vset:
            i = 0
            while vs[i] != v:
                i += 1
            if ts[i] == 'L':
                i -= 1
                while i >= 0 and (ts[i] != 'E' or vs[i] > 0): i -= 1
                if i >= 0:
                    vs[i] = v
            i = n-1
            while vs[i] != v:
                i -= 1
            if ts[i] == 'E':
                i += 1
                while i < n and (ts[i] != 'L' or vs[i] > 0): i += 1
                if i < n:
                    vs[i] = v
                else:
                    ext += 1

        #print ' '.join(ts)
        #print ' '.join(map(str, vs))
        #print

        for i in xrange(n):
            if vs[i] > 0 and ts[i] == 'E':
                j = i + 1
                while j < n and (vs[j] != vs[i] or ts[j] != 'L'): j += 1
                fdL = -1
                for k in xrange(i+1,j):
                    if vs[k] == 0:
                        if fdL == -1:
                            if ts[k] == 'L':
                                fdL = k
                        else:
                            if ts[k] == 'E':
                                vs[fdL] = vs[k] = vs[i]
                                fdL = -1


        ext = 0
        for v in vset:
            i = n-1
            while vs[i] != v:
                i -= 1
            if ts[i] == 'E':
                i += 1
                while i < n and (ts[i] != 'L' or vs[i] > 0): i += 1
                if i >= n:
                    ext += 1

        ans = 0
        for i in xrange(n):
            if vs[i] == 0: 
                if ts[i] == 'L':
                    if ans > 0: ans -= 1
                else:
                    ans += 1
        ans += ext



    if bad:
        ans = "CRIME TIME"

    print "Case #%s: %s" % (cas, ans)
