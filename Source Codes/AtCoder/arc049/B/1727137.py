from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt
from collections import deque
from bisect import bisect, bisect_left, bisect_right
INF = float("inf")


def ok(t, x_y_c_list):
    max_x_l, min_x_r, max_y_l, min_y_r = -INF, INF, -INF, INF
    for x, y, c in x_y_c_list:
        half = t / c
        x_l, x_r = x - half, x + half
        y_l, y_r = y - half, y + half
        max_x_l = max(max_x_l, x_l)
        min_x_r = min(min_x_r, x_r)
        max_y_l = max(max_y_l, y_l)
        min_y_r = min(min_y_r, y_r)

    return max_x_l <= min_x_r and max_y_l <= min_y_r


def main():
    N = int(input())
    x_y_c_list = []
    for _ in range(N):
        x, y, c = map(int, input().split())
        x_y_c_list.append((x, y, c))

    # [low, high)
    low, high, ans = -1, int(1e14) - 1, -1
    while high - low > 0.00001:
        middle = (low + high) / 2
        if ok(middle, x_y_c_list):
            ans = middle
            high = middle
        else:
            low = middle

    print(ans)


if __name__ == '__main__':
    main()