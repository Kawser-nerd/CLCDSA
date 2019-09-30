#!/usr/bin/env python3
import sys
INF = float("inf")


def solve(N: int, x: "List[int]", y: "List[int]", h: "List[int]"):

    # h?????????
    for i in range(N):
        if h[i] > 0:
            break

    # ????????????????????????h[i]?????
    cand = [[0]*101 for _ in range(101)]
    for j in range(101):
        for k in range(101):
            cand[j][k] = h[i]+abs(x[i]-k)+abs(y[i]-j)

    # ??????????????????
    for i in range(101):
        for j in range(101):
            flags = [max(cand[i][j]-abs(x[k]-j)-abs(y[k]-i), 0) == h[k]
                     for k in range(N)]
            if all(flags):
                print(j, i, cand[i][j])
                return

    return


def main():

    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    x = [int()] * (N)  # type: "List[int]"
    y = [int()] * (N)  # type: "List[int]"
    h = [int()] * (N)  # type: "List[int]"
    for i in range(N):
        x[i] = int(next(tokens))
        y[i] = int(next(tokens))
        h[i] = int(next(tokens))
    solve(N, x, y, h)


if __name__ == '__main__':
    main()