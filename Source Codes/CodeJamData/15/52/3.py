#!/usr/bin/python
__author__ = 'Tianren Liu'

import sys
import numpy as np



if __name__ == "__main__":
    T = int(sys.stdin.readline())
    for t in xrange(T):
        N,K = map(int, sys.stdin.readline().split())
        S = map(int, sys.stdin.readline().split())

        d = [S[i+1]-S[i] for i in range(N-K)]
        P = []
        Q = 0
        for i in range(K):
            cur = dmin = dmax = 0
            for j in range(i,N-K,K):
                cur += d[j]
                dmin = min(dmin, cur)
                dmax = max(dmax, cur)
            P.append(dmax-dmin)
            Q += -dmin

        res = max(P)
        remain = (S[0]-Q) % K
        if max(P)*K - sum(P) < remain:
            res += 1

        print "Case #{}: {}".format(t+1, res)
