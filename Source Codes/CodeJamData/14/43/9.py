#!/usr/bin/env python

dx = (0, -1, 0, 1)
dy = (1, 0, -1, 0)

def solve(W, H, B, buildings):
    field = [[1] + [0] * W + [1] for i in xrange(H)]
    for b in buildings:
        for y in xrange(b[1], b[3] + 1):
            for x in xrange(b[0] + 1, b[2] + 2):
                field[y][x] = 1
    field = [[1] * (W + 2)] + field + [[3] * (W + 2)]
    res = 0
    for x in xrange(1, W + 1):
        mem = [(0, x, 0)]
        while mem:
            y, x, d = mem.pop()
            y += dy[d]
            x += dx[d]
            if field[y][x] == 3:
                res += 1
                break
            if field[y][x] != 0:
                continue
            field[y][x] = 2
            for i in xrange(4):
                mem.append((y, x, (d - 1 + i) % 4))
    return res

T = int(raw_input())
for x in xrange(1, T + 1):
    W, H, B = map(int, raw_input().split())
    buildings = [map(int, raw_input().split()) for i in xrange(B)]
    print 'Case #%d: %s' % (x, solve(W, H, B, buildings))
