#!/usr/bin/env python3


def tidy(N):
    return list(N) == sorted(N)

def solve(N):
    if N == '0':
        return ''
    if tidy(N) or len(N) <= 1:
        return N
    return solve(str(int(N[:-1]) - 1)) + '9'

T = int(input())

for case_number in range(1, T+1):
    N = input()  # a string
    print('Case #%d:' % case_number, solve(N))
