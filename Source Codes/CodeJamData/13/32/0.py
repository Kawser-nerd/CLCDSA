#! /usr/bin/env python

from sys import stdin
from math import sqrt

ntest = input()

for test in xrange(ntest):
    x, y = [int(i) for i in stdin.readline().strip().split(' ')]
    l = abs(x) + abs(y)
    n = int(sqrt(2*l)) - 1
    while True:
        # test with n jumps
        path = []
        curx = x
        cury = y
        for i in xrange(n, 0, -1):
            if abs(curx) > abs(cury):
                if curx > 0:
                    path.append('E')
                    curx -= i
                else:
                    path.append('W')
                    curx += i
            else:
                if cury > 0:
                    path.append('N')
                    cury -= i
                else:
                    path.append('S')
                    cury += i
        if curx == 0 and cury == 0:
            result = ''.join(path[::-1])
            break
        n += 1

    print "Case #{}: {}".format(test+1, result)
