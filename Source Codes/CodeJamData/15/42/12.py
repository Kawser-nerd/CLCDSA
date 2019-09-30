#!/usr/bin/env python3

T = int(input())
for case in range(1, T+1):
    N, V, X = input().split()
    N = int(N)
    V = float(V)
    X = float(X)
    RC = [tuple(float(i) for i in input().split()) for _ in range(N)]
    pos = []
    neg = []
    rat = 0
    for r, c in RC:
        t = c - X
        if t > 0:
            pos.append([t, r])
        elif t < 0:
            neg.append([-t, r])
        else:
            rat += r
    pos.sort()
    neg.sort()
    while pos and neg:
        pt, pr = pos[0]
        nt, nr = neg[0]
        if pt * pr > nt * nr:
            dr = (nt * nr) / pt
            rat += dr + nr
            pos[0][1] -= dr
            del neg[0]
        else:
            dr = (pt * pr) / nt
            rat += dr + pr
            neg[0][1] -= dr
            del pos[0]
    if rat:
        ans = V / rat
    else:
        ans = 'IMPOSSIBLE'
    print("Case #{}: {}".format(case, ans))

