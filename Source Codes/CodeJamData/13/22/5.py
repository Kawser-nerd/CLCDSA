def parse(inFile):
    return tuple(inFile.getInts())

import sys

sys.setrecursionlimit(2000)

a_cache = {}

def ans(r, num):
    if not a_cache.has_key((r, num)):
        if (num == 0):
            return 1.0
        if (num == r):
            return 1.0 / (1 << r)
        a_cache[(r, num)] = (ans(r-1, num-1) + ans(r-1, num)) / 2
    return a_cache[(r, num)]

def solve((N,X,Y)):
    if (X <= 0):
        X = -X
    lvl = (X + Y) / 2
    if (N >= 2 * lvl * lvl + 3 * lvl + 1):
        return "1"
    if (N <= 2 * (lvl - 1) * (lvl - 1) + 3 * (lvl - 1) + 1):
        return "0"
    if (X == 0):
        return "0"

    r = N - (2 * (lvl - 1) * (lvl - 1) + 3 * (lvl - 1) + 1)

    if (r <= Y):
        return "0"
    if (r >= Y + 2 * lvl + 1):
        return "1"

    return str(ans(r, Y + 1))

if __name__ == "__main__":
    from GCJ import GCJ
    GCJ(parse, solve, "/Users/lpebody/gcj/2013_1b/b", "B").run()
