from collections import Counter, defaultdict
import math
import random
from decimal import Decimal, ROUND_HALF_UP, ROUND_CEILING
from functools import lru_cache, reduce
from itertools import combinations_with_replacement, product, combinations


def read_int():
    return int(input())


def read_int_n():
    return list(map(int, input().split()))


def read_str():
    return input()


def read_str_n():
    return list(map(str, input().split()))


def mt(f):
    import time
    import sys

    def wrap(*args, **kwargs):
        s = time.time()
        ret = f(*args, **kwargs)
        e = time.time()

        print(e - s, 'sec', file=sys.stderr)
        return ret

    return wrap


@mt
def slv(S, X, P):
    X_ = [[P[i], [x]] for i, x in enumerate(X)]
    i = 0
    j = len(X_) - 1
    # while len(X_) != 1:
    while i < j:

        if X_[i][0] >= X_[j][0]:
            X_[i][0] += X_[j][0]
            X_[i][1] += X_[j][1]
            j -= 1
        else:
            X_[j][0] += X_[i][0]
            X_[j][1] += X_[i][1]
            i += 1

    t = 0
    pos = S
    p0 = S
    p1 = S
    for o in X_[i][1]:
        if p0 < o < p1:
            continue

        t += abs(pos - o)
        if o < pos:
            p0 = o
        else:
            p1 = o
        pos = o

    return t


def main():

    N, S = read_int_n()
    X = []
    P = []
    for _ in range(N):
        x, p = read_int_n()
        X.append(x)
        P.append(p)

    # import random
    # N = 100000
    # S = N / 2
    # X = [x + 1 for x in range(N)]
    # P = [random.randint(1, 1000000000) for _ in range(N)]

    print(slv(S, X, P))


if __name__ == '__main__':
    main()