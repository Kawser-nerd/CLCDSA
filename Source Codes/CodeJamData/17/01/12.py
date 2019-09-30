#!/usr/bin/env python3


def toggle(cake):
    return '-+'[cake == '-']

def solve(S, K):
    S = list(S)
    flip_count = 0
    for s in range(len(S) - K + 1):
        if S[s] == '+':
            continue
        for k in range(K):
            S[s + k] = toggle(S[s + k])
        flip_count += 1
    if '-' in S:
        return 'IMPOSSIBLE'
    return flip_count
        

T = int(input())

for case_number in range(1, T+1):
    S, K = input().split()
    K = int(K)
    print('Case #%d:' % case_number, solve(S, K))
