import sys, os
from math import *

T = int(sys.stdin.readline())

def wins(name, board, x, y, dirx, diry, K):
    for i in xrange(K):
        _x = x + dirx * i
        _y = y + diry * i
        if board[_x][_y] != name:
            return False
    return True

def winsatall(name, board, N, K):
    for x in xrange(N-K+1):
        for y in xrange(N-K+1):
            if wins(name, board, x, y, 1, 1, K):
                return True
            if wins(name, board, x + K - 1, y, -1, 1, K):
                return True
    for x in xrange(N-K+1):
        for y in xrange(N):
            if wins(name, board, x, y, 1, 0, K):
                return True
            if wins(name, board, y, x, 0, 1, K):
                return True
    return False

for _t in xrange(T):
    N, K = map(int, sys.stdin.readline().split())
    board = []
    for i in xrange(N):
        board.append(['.'] * N)

    for i in xrange(N):
        s = sys.stdin.readline().strip()
        n = 0
        for j in xrange(N):
            if s[N-j-1] != '.':
                board[i][N-n-1] = s[N-j-1]
                n += 1
    # print '\n'.join([''.join(s) for s in board])
    # print

    r = winsatall('R', board, N, K)
    b = winsatall('B', board, N, K)

    print "Case #%d:" % (_t+1),
    if r and b:
        print "Both"
    elif r:
        print "Red"
    elif b:
        print "Blue"
    else:
        print "Neither"

