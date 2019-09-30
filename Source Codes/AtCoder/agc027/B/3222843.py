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

sys.setrecursionlimit(10000)


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
def slv(N, X, x):

    x.reverse()
    sa = [0]
    for a in x:
        sa.append(sa[-1]+a)

    ans = sys.maxsize
    for k in range(1, N+1):
        t = X*N
        for j in range(1, math.ceil(N/k)+1):
            s = (j-1)*k
            e = (j)*k
            if e >= len(sa):
                e = len(sa)-1

            if j == 1:
                t += 5*(sa[e]-sa[s])
            else:
                t += (2*j+1)*(sa[e]-sa[s])

        t += k*X
        ans = min(ans, t)
    return ans


def main():
    N, X = read_int_n()
    x = read_int_n()
    print(slv(N, X, x))


if __name__ == '__main__':
    main()