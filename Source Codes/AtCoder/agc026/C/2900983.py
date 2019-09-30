# -*- coding: utf-8 -*-
from collections import defaultdict

N = int(input())
S = input()
A, B = S[:N], S[N:]
D = defaultdict(int)
ans = 0

def paint(X, i):
    r = ""
    b = ""
    for j, k in enumerate(format(i, "b").zfill(N)):
        if k == "1":
            r += X[j]
        else:
            b += X[j]
    return r, b

for i in range(2**N):
    r, b = paint(A, i)
    D[(r, b)] += 1

for i in range(2**N):
    r, b = paint(B, i)
    ans += D[(b[::-1], r[::-1])]

print(ans)