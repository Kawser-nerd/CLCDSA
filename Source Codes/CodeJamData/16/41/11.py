#!/usr/bin/python3
__author__ = 'Tianren Liu'

import sys
import numpy as np

def solve(R, P, S):
    if (R < 0 or P < 0 or S < 0):
        return "IMPOSSIBLE"
    if R+P+S == 1:
        return 'R' if R > 0 else 'P' if P > 0 else 'S'
    Rn, Pn, Sn = (R+S-P)//2, (P-S+R)//2, (-R+S+P)//2
    if (Rn > R or Pn > P or Sn > S):
        return "IMPOSSIBLE"
    res = solve(Rn, Pn, Sn)
    if res == "IMPOSSIBLE":
        return "IMPOSSIBLE"
    else:
        nres = ''
        m = {'R':'RS', 'S':'SP', 'P':'PR'}
        for c in res:
            nres += m[c]
        return nres

def asort(S):
    if S == "IMPOSSIBLE":
        return S
    l = len(S)
    if l > 1:
        Sl = asort(S[:l//2])
        Sh = asort(S[l//2:])
        S = Sl + Sh if Sl < Sh else Sh + Sl
    return S

if __name__ == "__main__":
    T = int(sys.stdin.readline())
    for t in range(T):
        N, R, P, S = map(int, sys.stdin.readline().split())
        print("Case #{}: {}".format(t+1,asort(solve(R, P, S))))
