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
    min_cnt = num_cnt[min_a]
    max_cnt = num_cnt[max_a]
    # print(num_cnt)

    if max_a - min_a >= 2:
        return 'No'
    elif len(num_cnt) == 1:
        if min_a == N - 1:
            return 'Yes'
        elif min_a * 2 <= N:
            return 'Yes'
        else:
            return 'No'
    elif A.count(1) >= 2:
        return 'No'
    elif min_cnt == 2 and max_cnt >= max_a:
        return 'Yes'
    elif min_cnt == min_a:
        return 'Yes'
    else:
        return 'No'


print(solve())