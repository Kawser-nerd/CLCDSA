#!/usr/bin/python3

import sys

def solve(n, s):
    cnt = 0
    while n > 0:
        m = 0
        for i in range(1, n):
            if s[i] < s[m]:
                m = i
        cnt += min(m, n-1-m)
        n = n-1
        del s[m]
    return cnt

t = int(sys.stdin.readline())

for test_case in range(1, t+1):
    n = int(sys.stdin.readline())
    s = [int(y) for y in sys.stdin.readline().split()]
    print('Case #%d: %d' % (test_case, solve(n, s)))
    