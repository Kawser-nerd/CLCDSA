#!/usr/bin/python
from sys import stdin

def _gcd(a, b):
    while a % b != 0:
        t = b
        b = a % b
        a = t

    return b

def gcd(a):
    N = len(a)

    g = a[0]

    for i in a:
        g = _gcd(g, i)

    return g

T = int(stdin.readline())
for t in range(1,T+1):
    A = map(int,stdin.readline().split())
    N = A[0]
    a = sorted(A[1:1 + N])

    b = []

    for i in range(1, N):
        if a[i] != a[0]:
            b.append(a[i] - a[0])

    g = gcd(b)

    r = g - a[0] % g

    if a[0] % g == 0:
        r = 0

    print "Case #%d: %d" % (t, r)

