from functools import wraps

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
    n, p, q, r, s = nums()
    v = [(i*p+q)%r+s for i in xrange(n)]
    sums = [0]*(n+1)
    for i in xrange(n):
        sums[i+1] = sums[i] + v[i]
    ans = sums[n]
    for i in xrange(1,n):
        L = 0
        R = i
        while R - L > 1:
            M = L + R >> 1
            ta = sums[M]
            tb = sums[i]-sums[M]
            if ta < tb:
                L = M
            else:
                R = M
        ans = min(ans, max(sums[L],sums[i]-sums[L],sums[n]-sums[i]), max(sums[R],sums[i]-sums[R],sums[n]-sums[i]))
        
    print "Case #%s: %.10f" % (cas, 1 - float(ans)/sums[n])
