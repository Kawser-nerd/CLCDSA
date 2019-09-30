from __future__ import division, print_function
from heapq import heappush, heappop
import sys

def solve(H, N, M, ceils, fllors):
    Q = [(0,0,0)]
    done = {}

    def move(t, ax, ay):
        h = H - t
        if t == 0:
            nt = 0
        elif h - floors[y][x] >= 20:
            nt = t+10
        else:
            nt = t+100
        if (ax,ay) in done and done[(ax,ay)] <= nt:
            return
        done[(ax,ay)] = nt
        #print(nt, ax, ay)
        heappush(Q, (nt, ax, ay))

    def trymove(ax, ay):
        if ax < 0 or ay < 0 or ax >= M or ay >= N:
            return
        c = min(ceils[ay][ax], ceils[y][x])
        if c - max(floors[y][x], floors[ay][ax]) < 50:
            return
        if c - h >= 50:
            move(t, ax, ay)
        else:
            move(t + 50-(c-h), ax, ay)

    while Q:
        t, x, y = heappop(Q)
        if x == M-1 and y == N-1:
            return t/10.0

        h = H - t
        trymove(x-1, y)
        trymove(x, y-1)
        trymove(x+1, y)
        trymove(x, y+1)
    return -1


def read_split():
    return sys.stdin.readline().split()

if __name__ == '__main__':
    NP = int(sys.stdin.readline())
    for i in xrange(NP):
        H, N, M = map(int, read_split())
        ceils = [map(int, read_split()) for _ in xrange(N)]
        floors = [map(int, read_split()) for _ in xrange(N)]
        print("Case #%d: %s" % (i+1, solve(H, N, M, ceils, floors)))
