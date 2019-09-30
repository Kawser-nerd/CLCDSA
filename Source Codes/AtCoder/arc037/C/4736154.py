#!/usr/bin/env python3
import bisect


def solve(n, k, a, b):

    b.sort()

    lo = 0
    hi = 10 ** 18
    while lo + 1 < hi:
        mid = (lo + hi) // 2
        c = 0
        for ai in a:
            p = mid // ai
            j = bisect.bisect_right(b, p)
            c += j
        if k <= c:
            hi = mid
        else:
            lo = mid

    return hi


def main():
    n, k = input().split()
    n = int(n)
    k = int(k)
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    print(solve(n, k, a, b))


if __name__ == '__main__':
    main()