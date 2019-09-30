from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt
from collections import deque
from bisect import bisect, bisect_left, bisect_right
import sys
sys.setrecursionlimit(100000)
INF = float("inf")

dy = [0, 1, 1]
dx = [1, 0, 1]


def inside(y: int, x: int, H: int, W: int) -> bool:
    return 0 <= y < H and 0 <= x < W


field = []
memo = [[None] * 101 for _ in range(101)]
def can_win(y, x, H, W):
    if memo[y][x] is not None:
        return memo[y][x]

    for i in range(3):
        ny, nx = y + dy[i], x + dx[i]

        if not inside(ny, nx, H, W):
            continue
        if field[ny][nx] == "#":
            continue

        if not can_win(ny, nx, H, W):
            memo[y][x] = True
            return True
    memo[y][x] = False
    return False


def main():
    H, W = map(int, input().split())
    for _ in range(H):
        field.append(list(input()))

    print("First" if can_win(0, 0, H, W) else "Second")


if __name__ == '__main__':
    main()