#!/usr/bin/python
#coding: utf-8

import os, sys
import math

def solve(input):
    def split(func, sep=' '):
        return map(func, input.readline().strip().split(sep))

    N = split(int)[0]
    d, l = [None] * N, [None] * N
    for i in range(N):
        d[i], l[i] = split(int)
    D = split(int)[0]

    #result = [0 for i in range(N)]
    #def dfs(i, lnow):
    #    if lnow <= result[i]:
    #        return False
    #    result[i] = lnow
    #    if D - d[i] <= lnow:
    #        return True
    #    for j in range(i+1, N):
    #        if d[j] - d[i] <= lnow:
    #            if dfs(j, min(d[j] - d[i], l[j])):
    #                return True
    #    return False

    dp = [None] * N
    dp[0] = d[0]
    for i in range(0, N):
        if D - d[i] <= dp[i]:
            return 'YES'
        for j in range(i+1, N):
            if d[j] - d[i] <= dp[i]:
                dp[j] = max(dp[j], min(d[j] - d[i], l[j]))
            else:
                break

    return 'NO'

if __name__ == '__main__':
    with open(sys.argv[1], 'r') as input:
        T = int(input.readline().strip())
        for t in range(1, T+1):
            print 'Case #%d: %s' % (t, solve(input))
