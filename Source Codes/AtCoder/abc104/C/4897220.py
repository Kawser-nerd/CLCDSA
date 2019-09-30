#!/usr/bin/env python3
import sys
import itertools
import collections
import functools
import math
import operator
from queue import Queue
INF = float("inf")


def dfs(curr, goal, count, probs):
    if curr >= goal:
        return count

    if len(probs) == 0:
        return INF

    # ??????????
    m1 = dfs(curr, goal, count, probs[:-1])

    # ??????????
    m2 = dfs(curr+probs[-1][0] * probs[-1][1] + probs[-1][2],
             goal, count+probs[-1][1], probs[:-1])

    # ????????????
    m3 = INF
    s = goal-curr
    if (probs[-1][0] * probs[-1][1]) >= s:
        m3 = count + int(math.ceil(s / probs[-1][0]))

    # print(m1, m2, m3, curr, count, probs)
    return min(m1, m2, m3)


def solve(D: int, G: int, p: "List[int]", c: "List[int]"):

    probs = []
    for i in range(D):
        probs.append([100*(i+1), p[i], c[i]])

    m = dfs(0, G, 0, probs)
    print(m)

    return


def main():

    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    D = int(next(tokens))  # type: int
    G = int(next(tokens))  # type: int
    p = [int()] * (D)  # type: "List[int]"
    c = [int()] * (D)  # type: "List[int]"
    for i in range(D):
        p[i] = int(next(tokens))
        c[i] = int(next(tokens))
    solve(D, G, p, c)


if __name__ == '__main__':
    main()