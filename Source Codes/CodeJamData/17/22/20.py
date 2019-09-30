#!/usr/bin/python

from __future__ import division
from gcj import *

# boolean flags, reachable via OPTS.flagname. Space separated in string
FLAGS = ''


def case():
    N, R, O, Y, G, B, V = ints()

    init = dict(R=R, O=O, Y=Y, G=G, B=B, V=V)
    Bh = B - O
    Yh = Y - V
    Rh = R - G

    if B == O and B+O==N: return 'BO' * (N//2)
    if Y == V and Y+V==N: return 'YV' * (N//2)
    if R == G and R+G==N: return 'RG' * (N//2)

    IMPOSSIBLE = 'IMPOSSIBLE'

    if min(Bh, Yh, Rh) < 0:
        return IMPOSSIBLE
    if O and not Bh: return IMPOSSIBLE
    if V and not Yh: return IMPOSSIBLE
    if G and not Rh: return IMPOSSIBLE

    h = dict(B=Bh, Y=Yh, R=Rh)
    big = sorted(h.keys(), key=lambda k: -h[k])

    contra = dict(R='G', B='O', Y='V')

    avail = dict(init)

    res = []

    def add(L):
        res.append(L)
        avail[L] -= 1
    def addWithContra(L):
        add(L)
        while avail[contra[L]]:
            add(contra[L])
            add(L)

    for i in range(h[big[0]]):
        addWithContra(big[0])
        y = 0
        if i < h[big[1]]:
            addWithContra(big[1])
            y = 1
        if i >= h[big[0]] - h[big[2]]:
            addWithContra(big[2])
            y = 1
        if not y:
            return IMPOSSIBLE

    return ''.join(res)

if __name__ == '__main__':
    main()
