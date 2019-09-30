#!/usr/bin/python2
# -*- coding: utf-8 -*-

import sys
import os

def test(tt):
    p = [1.0]
    for x in tt:
        newp = [0.0] * (len(p) + 1)
        for i, v in enumerate(p):
            newp[i] += p[i] * (1.0 - x)
            newp[i+1] += p[i] * x
        p = newp
    return p[len(tt)/2]

def main():
    T = int(sys.stdin.readline())
    for t in xrange(1, T+1):
        N, K = map(int, sys.stdin.readline().split())
        A = map(float, sys.stdin.readline().split())
        ret = 0.0
        A.sort()
        for k in xrange(K+1):
            tt = A[:k] + A[N-K+k:]
            assert len(tt) == K
            ret = max(ret, test(tt))
        print "Case #%s: %.7f" % (t, ret)




if __name__ == '__main__':
    main()
