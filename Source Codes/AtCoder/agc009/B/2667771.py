#!/usr/bin/env python3

import sys, math, copy
# import fractions, itertools
# import numpy as np
# import scipy

sys.setrecursionlimit(1000000)

HUGE = 2147483647
HUGEL = 9223372036854775807
ABC = "abcdefghijklmnopqrstuvwxyz"

class Node:
    def __init__(self):
        self.children0 = []
        self.parent0 = -1
        self.depth = -1

    def get_depth(self):
        if self.depth == -1:
            childdepths = sorted([nodes[ch0].get_depth() for ch0 in self.children0], reverse=True)
            res = 0
            for i0, cd in enumerate(childdepths):
                res = max(res, cd + i0 + 1)
            self.depth = res
        return self.depth

def main():
    for i0 in range(1, N):
        pa1 = int(input())
        assert pa1 >= 1
        pa0 = pa1 - 1
        nodes[i0].parent0 = pa0
        nodes[pa0].children0.append(i0)

    print(nodes[0].get_depth())

N = int(input())
nodes = [Node() for i in range(N)]
main()