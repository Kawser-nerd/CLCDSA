#!/usr/bin/python
#coding: utf-8

import os, sys
import math

from operator import itemgetter

def solve(input):
    def split(func, sep=' '):
        return map(func, input.readline().strip().split(sep))

    N, W, L = split(int)
    r = split(int)
    r = sorted(list(enumerate(r)), key=itemgetter(1))
    result = [None] * N
    
    i, w, l = 0, 0, 0
    while i < N and l <= L:
        if w == 0:
            w = r[i][1]
            result[r[i][0]] = (0, l if l == 0 else l+r[i][1])
            i += 1
        elif w + 2 * r[i][1] <= W:
            result[r[i][0]] = (w+r[i][1],l if l == 0 else l+r[i][1])
            w += 2 * r[i][1]
            i += 1
        elif w + r[i][1] <= W:
            result[r[i][0]] = (w+r[i][1],l if l == 0 else l+r[i][1])
            w = 0
            l += r[i][1] * (1 if l == 0 else 2)
            i += 1
        else:
            w = 0
            l += r[i-1][1] * (1 if l == 0 else 2)

    return 'impossible' if i < N else ' '.join(['%s %s' % result[j] for j in range(N)])

if __name__ == '__main__':
    with open(sys.argv[1], 'r') as input:
        T = int(input.readline().strip())
        for t in range(1, T+1):
            print 'Case #%d: %s' % (t, solve(input))
