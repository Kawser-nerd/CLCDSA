#!/usr/bin/python
__author__ = 'Tianren Liu'

import sys
import numpy as np

def solve(N, V, X, RC):
    RC.sort(key=lambda x:x[1])

    mintime = "IMPOSSIBLE"
    if RC[0][1] > X or RC[-1][1] < X: 
        return "IMPOSSIBLE"

    maxratio = sum([rc[0] for rc in RC if rc[1] == X])
    subRC = [rc for rc in RC if rc[1] < X]
    supRC = [rc for rc in RC if rc[1] > X]
    subRC.sort(key=lambda x:x[1])
    supRC.sort(key=lambda x:x[1], reverse=True)

    while len(subRC) > 0 and len(supRC) > 0:
        subr, subc = subRC.pop()
        supr, supc = supRC.pop()
        if (supc-X)*supr >= (X-subc)*subr:
            supr -= (X-subc)*subr/(supc-X)
            supRC.append((supr,supc))
            maxratio += (X-subc)*subr/(supc-X) + subr
        else:
            subr -= (supc-X)*supr/(X-subc)
            subRC.append((subr,subc))
            maxratio += (supc-X)*supr/(X-subc) + supr

    # print subRC, supRC
    return V/(maxratio)
    
if __name__ == "__main__":
    T = int(sys.stdin.readline())
    for t in xrange(T):
        para = sys.stdin.readline().split()
        N = int(para[0]) 
        V, X = map(float, para[1:])
        print( "Case #{}: {}".format(t+1, solve(N,V,X,[map(float, sys.stdin.readline().split()) for i in range(N)])) )