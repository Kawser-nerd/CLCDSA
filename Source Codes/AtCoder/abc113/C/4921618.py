#!/usr/bin/env python3
import sys
from collections import defaultdict
from operator import itemgetter
INF = float("inf")


def solve(N: int, M: int, iPY):
    d = defaultdict(list)
    iPY.sort(key=itemgetter(2))
    for i, p, y in iPY:
        d[p].append([i, p, y])
    ans = []
    for k in d:
        for j, (i, p, y) in enumerate(d[k]):
            ans.append([i, "{0:06d}{1:06d}".format(p, j+1)])
    ans.sort()
    for a in ans:
        print(a[1])
    return


def main():

    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    M = int(next(tokens))  # type: int
    iPY = [[]] * (M)
    for i in range(M):
        iPY[i] = [i, int(next(tokens)), int(next(tokens))]
    solve(N, M, iPY)


if __name__ == '__main__':
    main()