#!/usr/bin/python3
__author__ = 'Tianren Liu'

import sys
import numpy as np

def solve(S):
    n = len(S)
    mat = np.zeros([n+1,n+1],int)
    # for s in range(n+1):
    #     mat[s,s] = 0
    for l in range(2,n+1,2):
        for s in range(n+1-l):
            t = s+l
            mat[s,t] = max([mat[s+1,j] + mat[j+1,t] + (10 if S[s]==S[j] else 5) for j in range(s+1, t+1, 2)])
    # print(mat)
    # print(n,mat[0,n])
    # print(S)
    return mat[0,n]

if __name__ == "__main__":
    T = int(sys.stdin.readline())
    for t in range(T):
        S = sys.stdin.readline()
        S = [s for s in S if s in {'J','C'}]
        print("Case #{}: {}".format(t+1,solve(S)))
