# coding:utf-8

import sys
from collections import defaultdict


input = sys.stdin.readline
INF = float('inf')
MOD = 10 ** 9 + 7


def inpl(): return list(map(int, input().split()))


A, B = inpl()

cnt = 1
num_cnt = defaultdict(int)
for n in range(B + 1, A + 1):
    i = 2
    while i * i <= n:
        if n % i == 0:
            cnt = 0
            while n % i == 0:
                cnt += 1
                n //= i
            num_cnt[i] += cnt
        i += 1

    if n != 1:
        # n????????????????
        num_cnt[n] += 1

ans = 1
for key in num_cnt.keys():
    ans *= num_cnt[key] + 1
    ans %= MOD

print(ans)