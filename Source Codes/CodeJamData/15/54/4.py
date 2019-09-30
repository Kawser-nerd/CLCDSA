#!/usr/bin/python
__author__ = 'Tianren Liu'

import sys
import numpy as np
import string


if __name__ == "__main__":
    T = int(sys.stdin.readline())
    for t in xrange(T):
        P = int(sys.stdin.readline())
        E = zip(map(int, sys.stdin.readline().split()), map(int, sys.stdin.readline().split()))

        B = []
        if E[0][1] > 1:
            fz = E[0][1]
            E = [(e,f/fz) for e,f in E]
            while fz > 1:
                B.append(0)
                fz = fz/2
        while len(E) > 1:
            b = E[1][0]
            Eb, Es = [], {}
            for e,f in E:
                if e in Es:
                    f -= Es[e]
                if f>0:
                    Eb.append((e,f))
                    if e+b in Es:
                        Es[e+b]+=f
                    else:
                        Es[e+b]=f
            B.append(b)
            E = Eb

        print "Case #{}: {}".format(t+1, string.join(map(str,B)))
