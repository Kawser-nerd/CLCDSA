#!/usr/bin/python
__author__ = 'Tianren Liu'

import sys
import numpy as np

if __name__ == "__main__":
    T = int(sys.stdin.readline())
    for t in xrange(T):
        N = int(sys.stdin.readline())
        if N == 0:
            print "Case #{}: INSOMNIA".format(t+1)
            continue
        seen = [False for _ in range(10)]
        remain = 10
        M = 0
        while remain > 0:
            M = M + N
            m = M
            while m > 0:
                r = m % 10
                m = m / 10
                if seen[r] == False:
                    seen[r] = True
                    remain -= 1
        print "Case #{}: {}".format(t+1, M)
