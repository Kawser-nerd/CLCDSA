#!/usr/bin/python
#coding: utf-8

import os, sys
import math

def solve(input):
    def split(func, sep=' '):
        return map(func, input.readline().strip().split(sep))

    s = split(int)[1:]
    ss = sum(s)
    def check(i, m):
        ns = s[i] + m * ss
        tmp = 1 - m
        for j, sss in enumerate(s):
            if j != i and s[j] < ns:
                tmp -= (ns - s[j]) / ss
                if tmp < 0:
                    return True
        return tmp <= 0
    result = []
    for i in range(len(s)):
        l, r = 0, 1.0
        while r - l > 1e-9:
            m = (r + l) / 2
            if check(i, m):
                r = m
            else:
                l = m
        result.append('%.6f' % (l * 100))
    return ' '.join(result)

if __name__ == '__main__':
    with open(sys.argv[1], 'r') as input:
        T = int(input.readline().strip())
        for t in range(1, T+1):
            print 'Case #%d: %s' % (t, solve(input))
