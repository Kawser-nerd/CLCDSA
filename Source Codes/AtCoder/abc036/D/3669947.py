#!/usr/bin/env python
import string
import sys
from collections import defaultdict
from itertools import chain, takewhile


def read(
    f, *shape, it=chain.from_iterable(sys.stdin), whitespaces=set(string.whitespace)
):
    def read_word():
        return f("".join(takewhile(lambda c: c not in whitespaces, it)).strip())

    if not shape:
        return read_word()
    elif len(shape) == 1:
        return [read_word() for _ in range(shape[0])]
    elif len(shape) == 2:
        return [[read_word() for _ in range(shape[1])] for _ in range(shape[0])]


def arr(*shape, fill_value=0):
    if len(shape) == 1:
        return [fill_value] * shape[fill_value]
    elif len(shape) == 2:
        return [[fill_value] * shape[1] for _ in range(shape[0])]


def debug(**kwargs):
    print(
        ", ".join("{} = {}".format(k, repr(v)) for k, v in kwargs.items()),
        file=sys.stderr,
    )


def main():
    n = read(int)
    G = defaultdict(list)
    for _ in range(n - 1):
        a, b = read(int, 2)
        G[a].append(b)
        G[b].append(a)

    MOD = 1000000000 + 7

    def dfs(cur, prev):
        w, b = 1, 1
        for node in G[cur]:
            if node != prev:
                w_child, b_child = dfs(node, cur)
                w *= (w_child + b_child) % MOD
                w %= MOD
                b *= w_child
                b %= MOD
        return w, b

    w, b = dfs(1, -1)
    print((w + b) % MOD)


if __name__ == "__main__":
    main()