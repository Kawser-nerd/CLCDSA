#!/usr/bin/python
__author__ = 'Tianren Liu'

import sys
import numpy as np

def update(D, ms, w):
    wp = []
    nz = 0
    for lb,n in w:
        if lb <= ms-D:
            nz = n
        elif lb <= ms:
            wp.append((lb,n))
        else:
            break
    w = [(ms-D,nz)] + wp

    wd = []
    ncur = nz
    for lb,n in w[1:]:
        wd.append((lb,n-ncur))
        ncur = n

    return nz,wd


def solver(D,S,M,Rs):
    # print S
    # print M
    C = [set() for i in xrange(N)]
    W = [None for i in xrange(N)]

    for i in xrange(N-1,-1,-1):
        nz = 1
        wd = []
        ms = S[i]
        for c in C[i]:
            nzp, wdp = update(D, ms, W[c])
            nz += nzp
            wd.extend(wdp)
        wd.sort(key=lambda (s,n):s)
        res = []
        scur = ms-D
        ncur = nz
        for s,nd in wd:
            if s != scur:
                if len(res) == 0 or res[-1][1] != ncur:
                    res.append((scur,ncur))
            scur = s
            ncur += nd
        res.append((scur,ncur))
        res.append((ms+1,0))
        W[i] = res
        if i != 0:
            C[M[i]].add(i)
    return max([n for s,n in W[0]])


if __name__ == "__main__":
    T = int(sys.stdin.readline())
    for t in xrange(T):
        N,D = map(int, sys.stdin.readline().split())
        Sz, As, Cs, Rs = map(int, sys.stdin.readline().split())
        Mz, Am, Cm, Rm = map(int, sys.stdin.readline().split())
        Sc = Sz
        S = [Sz]
        for i in range(1,N):
            Sc = (Sc * As + Cs) % Rs
            S.append(Sc)
        Mc = Mz
        M = [None]
        for i in range(1,N):
            Mc = (Mc * Am + Cm) % Rm
            M.append(Mc%i)
        print( "Case #{}: {}".format(t+1, solver(D,S,M,Rs)))
