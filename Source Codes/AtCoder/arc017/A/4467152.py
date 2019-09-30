# https://atcoder.jp/contests/arc017/tasks/arc017_1

import itertools
import collections
import bisect


def is_prime(n):
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    i = 3
    while i * i <= n:
        if n % i == 0:
            return False
        i += 2
    return True


def main():
    N = int(input())
    print("YES" if is_prime(N) else "NO")


if __name__ == '__main__':
    main()