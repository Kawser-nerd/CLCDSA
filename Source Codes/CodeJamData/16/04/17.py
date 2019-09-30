#!/usr/bin/python3
__author__ = 'Tianren Liu'

import sys
import numpy as np

if __name__ == "__main__":
    T = int(sys.stdin.readline())
    for t in range(T):
        K,C,S = map(int, sys.stdin.readline().split())
        if K > C * S:
            print("Case #{}: IMPOSSIBLE".format(t+1))
        else:
            print("Case #{}:".format(t+1), end="")
            for i in range(0,K,C):
                N = 0
                for j in range(i,i+C):
                    N = K*N + min(j,K-1);
                print(" {}".format(N+1), end="")
            print()
