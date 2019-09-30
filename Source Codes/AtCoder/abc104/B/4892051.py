#!/usr/bin/env python3
import sys
import itertools
import collections
import functools
import math
from queue import Queue
INF = float("inf")


def solve(S: str):

    if S[0] != "A":
        print("WA")
        return

    if S[2:-1].count("C") != 1:
        print("WA")
        return

    flag = False
    for i, c in enumerate(S):
        if i == 0:
            continue
        if ord("a") <= ord(c) and ord(c) <= ord("z"):
            continue
        elif 1 < i and i < len(S)-1 and c == "C" and flag == False:
            # print("ga")
            flag = True
            continue
        else:
            print("WA")
            return
    print("AC")

    return


def main():

    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    S = next(tokens)  # type: str
    solve(S)


if __name__ == '__main__':
    main()