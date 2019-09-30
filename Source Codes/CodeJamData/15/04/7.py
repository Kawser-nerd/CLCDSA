#!/usr/bin/env python2.7

richard = 'RICHARD'
gabriel = 'GABRIEL'

T = int(raw_input())
for x in xrange(1, T + 1):
    X, R, C = map(int, raw_input().split())
    y = gabriel
    if X > 6:
        y = richard
    elif R * C % X != 0:
        y = richard
    elif X > max(R, C):
        y = richard
    elif (X + 1) / 2 > min(R, C):
        y = richard
    elif X == 4:
        if min(R, C) == 2:
            y = richard
    elif X == 5:
        if min(R, C) == 3 and max(R, C) < 10:
            y = richard
    elif X == 6:
        if min(R, C) == 3:
            y = richard
    print 'Case #{}: {}'.format(x, y)
