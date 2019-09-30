#!/usr/bin/python

from __future__ import print_function

import sys
import pprint

def diagonals(board):
    N = len(board)
    for x in xrange(N):
        yield [board[i][j] for i,j in zip(range(N), range(x,N))]
    for y in xrange(N):
        yield [board[i][j] for i,j in zip(range(y,N), range(N))]


def solve(board, K, color):
#    print(board)
    des = color*K
    # horizontal
    for line in board:
        if des in line:
            return True
    # vertical
    for col in xrange(len(board)):
        column = "".join(line[col] for line in board)
        if des in column:
            return True
    # rdiagonal
    for diag in diagonals(board):
        diag = "".join(diag)
        if des in diag:
            return True
    # ldiagonal
    board = ["".join(reversed(line)) for line in board]
    for diag in diagonals(board):
        diag = "".join(diag)
        if des in diag:
            return True

def main(filename):
    with open(filename, "r") as f:
        for case, line in enumerate(f):
            if not case:
                T = int(line.strip())
                continue
            if case > T:
                break
            N, K = (int(c) for c in line.split())
            board = []
            for i in xrange(N):
                line = next(f)
                line = [c for c in line if not c.isspace()]
                line.sort(key=lambda c: c==".", reverse=True)
                board.append("".join(line))
            red = solve(board, K, "R")
            blue = solve(board, K, "B")
            if red and blue:
                value = "Both"
            elif red:
                value = "Red"
            elif blue:
                value = "Blue"
            else:
                value = "Neither"
            print("Case #{0}: {1}".format(case,value))

if __name__ == "__main__":
    main(sys.argv[1])
    sys.exit(0)

