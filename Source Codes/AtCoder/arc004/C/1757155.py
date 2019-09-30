import sys
from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt, ceil, floor
from collections import deque
from bisect import bisect, bisect_left, bisect_right
from string import ascii_lowercase
INF = float("inf")
sys.setrecursionlimit(10**7)

# 4????, ?, ?, ??
dy = [0, -1, 0, 1]
dx = [1, 0, -1, 0]


def inside(y: int, x: int, H: int, W: int) -> bool: return 0 <= y < H and 0 <= x < W


def main():
    X, Y = map(int, input().split("/"))
    ans_list = []
    for n in range(max(0, 2 * X // Y - 10), 2 * X // Y + 10):
        a = n * (Y + n * Y - 2 * X)
        if a % (2 * Y) == 0:
            m = a // (2 * Y)
            if 0 < m <= n:
                ans_list.append("{0} {1}".format(n, m))

    if ans_list:
        print(*ans_list, sep="\n")
    else:
        print("Impossible")




if __name__ == '__main__':
    main()