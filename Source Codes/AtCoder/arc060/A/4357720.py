import bisect
from collections import Counter, deque
from itertools import combinations, accumulate
from math import factorial
from operator import neg
n, a = list(map(int, input().split()))
xs = list(map(lambda x: int(x) - a, input().split()))

xs.sort()
l, r = bisect.bisect_left(xs, 0), bisect.bisect_right(xs, 0)
low, n0, high = list(map(neg, xs[:l][::-1])), r - l, xs[r:]

def sums(arr):
    cntr = Counter([0])
    for v in arr:
        tmps = tuple(cntr.items())
        for u, cnt in tmps:
            cntr[u + v] += cnt
    del cntr[0]
    return cntr

lsums = sums(low)
hsums = sums(high)

ans = sum(hsums[a] * b for a, b in lsums.items())

ans *= 2 ** n0
ans += 2 ** n0 - 1

print(ans)