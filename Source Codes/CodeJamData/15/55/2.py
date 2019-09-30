#!/usr/bin/env python3

from itertools import accumulate
class Cheaters(Exception): pass

def calc(D, d):
    if any(i < 0 for i in d):
        raise Cheaters()
    if len(d) > 2*D:
        if d[2*D:] != d[:-2*D]:
            raise Cheaters()
    d = d[:2*D]
    e = [d[i]-d[D+i] for i in range(D)]
    e = [e[0]+e[D-1]] + [e[i+1]-e[i] for i in range(D-1)]
    if any(i%2 for i in e):
        raise Cheaters()
    e = [i//2 for i in e]
    res = sum(abs(i) for i in e)
    e = list(accumulate(e + [-i for i in e]))
    m = -min(e)
    e = [i+m for i in e]
    d = [i-j for i, j in zip(d, e)]
    if D > 1:
        return res + calc(D//2, d)
    else:
        return res

T = int(input())
for case in range(1, T+1):
    N, D = [int(i) for i in input().split()]
    d = [int(i) for i in input().split()]
    try:
        ans = calc(D, d)
    except Cheaters:
        ans = 'CHEATERS!'

    print("Case #{}: {}".format(case, ans))

