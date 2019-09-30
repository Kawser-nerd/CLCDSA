from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt
from collections import deque
from bisect import bisect, bisect_left, bisect_right
INF = float("inf")


def main():
    N = int(input())
    points = []
    for _ in range(N):
        x, y = map(int, input().split())
        points.append((x, y))
    rotated = [(x + y, x - y) for x, y in points]

    xs = [x for (x, y) in rotated]
    ys = [y for (x, y) in rotated]
    dx = max(xs) - min(xs)
    dy = max(ys) - min(ys)
    D = max(dx, dy)
    p1 = (min(xs) + D // 2, min(ys) + D // 2)
    p2 = (min(xs) + D // 2, max(ys) - D // 2)
    p3 = (max(xs) - D // 2, min(ys) + D // 2)
    p4 = (max(xs) - D // 2, max(ys) - D // 2)

    for x, y in [p1, p2, p3, p4]:
        px, py = (x + y) // 2, (x - y) // 2
        if len(set([abs(px - x) + abs(py - y) for (x, y) in points])) == 1:
            print(px, py)
            return


if __name__ == '__main__':
    main()