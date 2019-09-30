import bisect
import sys

sys.setrecursionlimit(10 ** 9 + 7)

n, m = map(int, input().split())
x, y = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

cache = {}
def f(t, airport):
    key = (t, airport)
    if key in cache:
        return cache[key]

    val = 0
    if airport:
        u = bisect.bisect_left(a, t)
        if u < n:
            val = max(val, f(a[u] + x, not airport))
    else:
        u = bisect.bisect_left(b, t)
        if u < m:
            val = max(val, f(b[u] + y, not airport) + 1)

    cache[key] = val
    return val

print(f(0, True))