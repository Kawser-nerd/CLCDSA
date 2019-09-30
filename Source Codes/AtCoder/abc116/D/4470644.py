# -*- coding: utf-8 -*-
import bisect
import heapq
import math
import random
import sys
from collections import Counter, defaultdict, deque
from decimal import ROUND_CEILING, ROUND_HALF_UP, Decimal
from functools import lru_cache, reduce
from itertools import combinations, combinations_with_replacement, product, permutations
from operator import add, mul, sub

sys.setrecursionlimit(100000)


def read_int():
    return int(input())


def read_int_n():
    return list(map(int, input().split()))


def read_float():
    return float(input())


def read_float_n():
    return list(map(float, input().split()))


def read_str():
    return input().strip()


def read_str_n():
    return list(map(str, input().split()))


def error_print(*args):
    print(*args, file=sys.stderr)


def mt(f):
    import time

    def wrap(*args, **kwargs):
        s = time.time()
        ret = f(*args, **kwargs)
        e = time.time()

        error_print(e - s, 'sec')
        return ret

    return wrap


@mt
def slv(N, K, TD):
    TD.sort(key=lambda x: x[1], reverse=True)

    c = Counter()
    base = 0
    rc = []
    for i in range(K):
        t, k = TD[i]
        c[t] += 1
        base += k
        if c[t] > 1:
            rc.append((t, k))

    mi = i
    ans = [base + len(c)**2]
    while True:
        if len(rc) == 0:
            break
        rt, rk = rc.pop()
        cc = len(c)
        d = (cc+1)**2 - cc**2
        for i in range(mi+1, len(TD)):
            if TD[i][0] not in c:
                c[TD[i][0]] += 1
                c[rt] -= 1
                base -= rk
                base += TD[i][1]
                mi = i
                ans.append(base + len(c)**2)
                break

        else:
            break
    return max(ans)


def main():
    # N = read_int()
    N, K = read_int_n()
    TD = [read_int_n() for _ in range(N)]
    print(slv(N, K, TD))


if __name__ == '__main__':
    main()