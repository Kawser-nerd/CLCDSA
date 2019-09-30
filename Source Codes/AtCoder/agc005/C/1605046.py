from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt
from collections import deque
from bisect import bisect, bisect_left, bisect_right
INF = float("inf")


def solve(c):
    max_length = max(c)
    for i in range(max_length, max_length // 2, -1):
        if c[i] < 2:
            return False

    if max_length % 2 == 0:
        if c[max_length // 2] != 1:
            return False
    else:
        if c[max_length - max_length // 2] != 2:
            return False

    return True


def main():
    N = int(input())
    c = Counter(list(map(int, input().split())))
    print("Possible" if solve(c) else "Impossible")


if __name__ == '__main__':
    main()