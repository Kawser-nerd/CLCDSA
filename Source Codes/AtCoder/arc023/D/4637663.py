#!/usr/bin/env python3


def gcd(a, b):
    a, b = max(a, b), min(a, b)
    while 0 < b:
        a, b = b, a % b
    return a


def solve(n, m, a, x):

    r = {}
    d = {}
    for ai in a:
        nd = {}
        nd[ai] = 1
        for g in d:
            c = d[g]
            ng = gcd(g, ai)
            if ng in nd:
                nd[ng] += c
            else:
                nd[ng] = c
        d = nd
        for g in d:
            if g in r:
                r[g] += d[g]
            else:
                r[g] = d[g]

    for xj in x:
        if xj in r:
            print(r[xj])
        else:
            print(0)


def main():
    n, m = input().split()
    n = int(n)
    m = int(m)
    a = []
    for _ in range(n):
        ai = input()
        ai = int(ai)
        a.append(ai)
    x = []
    for _ in range(m):
        xj = input()
        xj = int(xj)
        x.append(xj)

    solve(n, m, a, x)


if __name__ == '__main__':
    main()