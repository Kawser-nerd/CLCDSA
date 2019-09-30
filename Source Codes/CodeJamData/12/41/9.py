import sys

from functools import wraps

cache = {}

def cached(func):
    @wraps(func)
    def cached_func(*args):
        if args in cache:
            return cache[args]
        cache[args] = func(*args)
        return cache[args]
    return cached_func


D = []
L = []
total = 0

@cached
def canJump(a, b):
    d = min(L[b], D[b] - D[a])
    # print a, b, d, D, L, total
    if D[b] + d >= total:
        return True
    for i in xrange(b + 1, len(L)):
        if D[i] - D[b] > d:
            return False
        if canJump(b, i):
            return True
    return False

def compute(D, L, total):
    return "YES" if canJump(0, 1) else "NO"


def parse():
    global D, L, total
    N = int(sys.stdin.readline().strip())
    D = [0]
    L = [0]
    for i in xrange(N):
        d, l = map(int, sys.stdin.readline().strip().split(' '))
        D.append(d)
        L.append(l)
    total = int(sys.stdin.readline().strip())
    return (D, L, total)


if __name__ == "__main__":
    T = int(sys.stdin.readline().strip())
    for i in xrange(T):
        cache = {}
        data = parse()
        result = compute(*data)
        print "Case #%d: %s" % (i + 1, result)
