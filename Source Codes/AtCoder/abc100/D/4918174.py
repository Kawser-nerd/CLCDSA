#!/usr/bin/env python3
import sys
import itertools
INF = float("inf")


def solve(N: int, M: int, xyz):
    ans = []
    # ????????8??
    for p1, p2, p3 in itertools.product([-1, 1], repeat=3):
        # ??????
        m = -INF

        def f(x): return x[0]*p1+x[1]*p2+x[2]*p3

        xyz.sort(key=f, reverse=True)
        ans.append(sum([f(x) for x in xyz[:M]]))

    print(max(ans))
    return


def main():

    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    M = int(next(tokens))  # type: int
    xyz = [[]] * (N)  # type: "List[int]"
    for i in range(N):
        xyz[i] = [int(next(tokens)), int(next(tokens)), int(next(tokens))]
    solve(N, M, xyz)


if __name__ == '__main__':
    main()