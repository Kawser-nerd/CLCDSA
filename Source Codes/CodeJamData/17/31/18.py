#!/usr/bin/python3
import math


def solve():
    n, k = map(int, input().split())
    rh = []
    for _ in range(n):
        r, h = map(int, input().split())
        rh.append((r * h, r, h))
    rh = list(reversed(sorted(rh)))
    res = 0
    mx = 0
    mirh = rh[k-1][1:]
    marh = rh[0][1:]
    for s, r, h in rh[:k]:
        res += 2 * math.pi * r * h
        mx = max(mx, r)
        if (r, h) > marh:
            marh = r, h
    res1 = res + math.pi * mx * mx
    mis = 2 * math.pi * mirh[0] * mirh[1]
    for s, r, h in rh:
        if (r, h) > marh:
            res1 = max(res1, res + math.pi * r * r + 2 * math.pi * r * h - mis)
    return res1


if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        print('Case #%d: %.10f' % (i+1, solve()))
