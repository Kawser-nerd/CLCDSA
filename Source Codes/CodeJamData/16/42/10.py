#!/usr/bin/python3
__author__ = 'Tianren Liu'

import sys
import numpy as np

def solve(Choose,Target,p,dis):
    if len(dis)-1 + Choose < Target:
        return 0.
    if Choose == 0:
        # print('HIT')
        return dis[Target]
    if Choose > len(p):
        return 0

    ndis = np.zeros(len(dis)+1)
    ndis[:len(dis)] += dis * (1-p[0])
    ndis[1:] += dis * p[0]
    res = max(solve(Choose-1, Target, p[1:], ndis), solve(Choose, Target, p[1:], dis))
    # print (Choose,Target,p,dis,'=',res)
    return res

if __name__ == "__main__":
    T = int(sys.stdin.readline())
    for t in range(T):
        N,K = map(int, sys.stdin.readline().split())
        p = [float(f) for f in sys.stdin.readline().split()]
        print("Case #{}: {}".format(t+1, solve(K,K//2,p,np.array([1.]))))
