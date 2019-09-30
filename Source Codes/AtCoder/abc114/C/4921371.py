#!/usr/bin/env python3
import sys
import functools
import itertools
INF = float("inf")


@functools.lru_cache(maxsize=None)
def pow(b, n):
    return b**n


def f(n):
    # n??753?
    if n < 3:
        return 0

    return pow(3, n) - 3*pow(2, n) + 3


def solve(N: int):
    ketamax = len(str(N))

    ans = 0
    # ?
    for i in range(3, ketamax):
        ans += f(i)
    # print(ans)
    # ?????????????(O(N))
    for item in itertools.product(["3", "5", "7"], repeat=ketamax):
        if "3" not in item or "5" not in item or "7" not in item:
            continue
        elif int("".join(item)) > N:
            continue
        else:
            ans += 1
    print(ans)
    return


def main():

    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    solve(N)


if __name__ == '__main__':
    main()