#!/usr/bin/env python
import numpy as np

def pyramid_size(n):
    return 2 * n ** 2 - n

def pyramid_coordinates(x, y):
    if x == 0:
        return y / 2 + 1, 0
    return (y + abs(x)) / 2, y + 1

def prob(level, rem, h):
    p = np.zeros((2 * level + 1, 2 * level + 1))
    p[0, 0] = 1.0
    s = 0.0
    for l in xrange(0, 4 * level + 1):
        for x in xrange(0, 2 * level + 1):
            y = l - x
            if y < 0 or y > 2 * level:
                continue
            if x + y == rem and x >= h:
                s += p[x, y]
            if x < 2 * level and y < 2 * level:
                p[x + 1, y] += 0.5 * p[x, y]
                p[x, y + 1] += 0.5 * p[x, y]
            elif x < 2 * level and y == 2 * level:
                p[x + 1, y] += p[x, y]
            elif x == 2 * level and y < 2 * level:
                p[x, y + 1] += p[x, y]
    return s
    


             
def solve(n, x, y):
    level, h = pyramid_coordinates(x, y)
    if pyramid_size(level) + h > n:
        return 0.0
    if pyramid_size(level + 1) <= n:
        return 1.0
    return prob(level, n - pyramid_size(level), h)

if __name__ == "__main__":
    ncases = int(raw_input())
    for ncase in xrange(1, ncases + 1):
        n, x, y = map(int, raw_input().split())
        print "Case #%d: %.8lf" % (ncase, solve(n, x, y))
