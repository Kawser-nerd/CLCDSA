#!/usr/bin/env python
import sys

t = int(sys.stdin.readline())

def run():
    c,d = [int(x) for x in sys.stdin.readline().split()]
    n = 0;
    grid = []
    for l in range(c):
        p,v = [int(x) for x in sys.stdin.readline().split()]
        grid.append((p,v))
        n += v
    ret = 0.
    for i in range(len(grid)):
        for j in range(len(grid)):
            if j < i: continue
            n = 0
            for k in range(i,j+1):
                n += grid[k][1]
            blob = (d*(n-1)-(grid[j][0]-grid[i][0]))/2.
            if ret < blob:
                ret = blob

    return ret


for test in range(1,t+1):
    ret = run()
    print "Case #%d: %f" % (test, ret)

