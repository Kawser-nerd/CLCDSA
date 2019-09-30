#!/usr/bin/env python3
import math
Q = int(input())
num = lambda x: (x, max(0, (x - 1) // K))
sub = lambda xs, ys: [x - y for (x, y) in zip(xs, ys)]
for _ in range(Q):
    A, B, C, D = map(int, input().split())
    K = math.ceil(max(A, B) / (min(A, B) + 1))
    l, r = 0, A + 1
    while r - l > 1:
        m = (l + r) // 2
        rA, rB = sub((A, B), num(m))
        l, r = ((m, r), (l, m))[(rA + 1) * K < rB]

    f = ''
    for i in range(C - 1, D):
        na, nb = num(l)
        if i < na + nb:
            f += ('A', 'B')[i % (K + 1) == K] if i < nb * (K + 1) else 'A'
        else:
            nb, na = num(B - nb)
            j = A + B - i - 1
            f += ('B', 'A')[j % (K + 1) == K] if j < na * (K + 1) else 'B'
    print(f)