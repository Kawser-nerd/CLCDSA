# coding:utf-8

import sys


# input = sys.stdin.readline


def inpl(): return list(map(int, input().split()))


def solve():
    N, K = inpl()
    A = [int(input()) for _ in range(N)]
    
    if K == 1: return N

    prev = A[0]
    ans, cnt = 0, 1
    for i in range(1, N):
        cnt += 1

        if A[i] <= prev:
            cnt = 1

        if cnt >= K:
            ans += 1

        prev = A[i]
    
    return ans


print(solve())