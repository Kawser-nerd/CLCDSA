#!/usr/bin/env python3

from itertools import accumulate
qmul = lambda a, b: a ^ b ^ (a&6==b&6) ^ (6*(a//2^a//4)&6==b&6)

T = int(input())
for case in range(1, T+1):
    rep = int(input().split()[1])
    rep = min(rep, rep%4+8)
    seq = accumulate((2*ord(c)-208 for c in input()*rep), qmul)
    ans = 'YES' if 2 in seq and 6 in seq and list(seq)[-1] == 1 else 'NO'
    print("Case #{}: {}".format(case, ans))

