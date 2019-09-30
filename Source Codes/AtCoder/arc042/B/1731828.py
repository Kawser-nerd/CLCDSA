from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt
from collections import deque
from bisect import bisect, bisect_left, bisect_right
INF = float("inf")


def d(x0, y0, a, b, c):
    return abs(a * x0 + b * y0 + c) / sqrt(a ** 2 + b ** 2)


def main():
    x0, y0 = map(int, input().split())
    N = int(input())
    dot_list = []
    for _ in range(N):
        x1, y1 = map(int, input().split())
        dot_list.append((x1, y1))
    dot_list += [dot_list[0]]

    ans = INF
    for i in range(N):
        x1, y1 = dot_list[i]
        x2, y2 = dot_list[i + 1]
        a = y2 - y1
        b = x2 - x1
        c = -a * x1 + b * y1

        dist1 = d(x0, y0, a, -b, c)
        dist2 = sqrt((x0 - x1) ** 2 + (y0 - y1) ** 2)
        ans = min(ans, min(dist1, dist2))

    print("{0:.7f}".format(ans))


if __name__ == '__main__':
    main()