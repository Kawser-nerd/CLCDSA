import operator
from bisect import bisect_left
from math import pi
import decimal


def lis(A):
    L = [A[0]]
    for a in A[1:]:
        if a > L[-1]:
            L.append(a)
        else:
            L[bisect_left(L, a)] = a
    return len(L)


def solve():
    x1, y1, x2, y2 = map(int, input().split())
    if x1 > x2:
        x1, y1, x2, y2 = x2, y2, x1, y1
    is_down = y1 > y2
    if is_down:
        y1, y2 = -y1, -y2
    base = decimal.Decimal(100) * (x2 - x1 + y2 - y1)

    n = int(input())
    fountains = []
    for _ in range(n):
        x, y = map(int, input().split())
        if is_down:
            y = -y
        if x < x1 or x2 < x or y < y1 or y2 < y:
            continue
        fountains.append((x, y))

    if not fountains:
        return str(base)

    dpi = decimal.Decimal(pi)

    fountains.sort()
    fountains_y = list(map(operator.itemgetter(1), fountains))
    mc = lis(fountains_y)
    if mc == min(x2 - x1, y2 - y1) + 1:
        dist = base + (dpi * 5 - 20) * (mc - 1) + dpi * 10 - 20
    else:
        dist = base + (dpi * 5 - 20) * mc
    return str(dist)


print(solve())