# coding:utf-8

import sys
from collections import Counter


input = sys.stdin.readline
INF = float('inf')
MOD = 10 ** 9 + 7


def inpl(): return list(map(int, input().split()))


def solve():
    N = int(input())
    A = inpl()

    max_a = max(A)
    min_a = min(A)
    num_cnt = Counter(A)

    if max_a - min_a > 1:
        return 'No'

    if len(num_cnt) == 1:
        if max_a == N - 1 or 2 * max_a <= N:
            return 'Yes'
        else:
            return 'No'

    not_alone = num_cnt[max_a]
    alone = num_cnt[min_a]
    if not_alone >= (max_a - alone) * 2 and alone < max_a:
        return 'Yes'

    return 'No'


print(solve())