import sys
from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt, ceil, floor
from collections import deque
from bisect import bisect, bisect_left, bisect_right
from string import ascii_lowercase
INF = float("inf")
sys.setrecursionlimit(10**7)

# 8????, ?, ?, ????, ??, ??, ???
dy = [0, -1, 0, 1, 1, -1, -1, 1]
dx = [1, 0, -1, 0, 1, 1, -1, -1]


def inside(y: int, x: int, H: int, W: int) -> bool: return 0 <= y < H and 0 <= x < W


def func(board, p):
    ans = 0
    for i in range(19):
        n = 0
        for x in range(19):
            if board[i][x] == p:
                n += 1
            else:
                ans = max(ans, n)
                n = 0
        ans = max(ans, n)

        n = 0
        for y in range(19):
            if board[y][i] == p:
                n += 1
            else:
                ans = max(ans, n)
                n = 0
        ans = max(ans, n)

    for y in range(19):
        for x in range(19):
            ny, nx = y, x
            n = 0
            while inside(ny, nx, 19, 19):
                if board[ny][nx] == p:
                    n += 1
                else:
                    ans = max(ans, n)
                    n = 0
                ny, nx = ny + 1, nx + 1
            ans = max(ans, n)

            ny, nx = y, x
            n = 0
            while inside(ny, nx, 19, 19):
                if board[ny][nx] == p:
                    n += 1
                else:
                    ans = max(ans, n)
                    n = 0
                ny, nx = ny + 1, nx - 1
            ans = max(ans, n)
    return ans


def solve(b, w, board):
    if b != w and b != w + 1:
        return False
    if b == 0 and w == 0:
        return True

    win = "x" if b == w else "o"
    lose = "o" if b == w else "x"

    if func(board, lose) >= 5:
        return False
    for y in range(19):
        for x in range(19):
            if board[y][x] != win:
                continue
            board[y][x] = "."
            if func(board, win) < 5:
                return True
            board[y][x] = win

    return False


def main():
    board = []
    b, w = 0, 0
    for _ in range(19):
        line = input()
        board.append(list(line))
        b += line.count("o")
        w += line.count("x")
    print("YES" if solve(b, w, board) else "NO")


if __name__ == '__main__':
    main()