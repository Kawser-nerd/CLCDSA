#!/usr/bin/python

import sys

def readdata():
    def rl():
        return sys.stdin.readline().strip().split(' ')
    n = int(rl()[0])
    cases = []
    for i in range(n):
        n, A, B, C, D, x, y, M = (int(x) for x in rl())
        points = [(x,y)]
        for i in xrange(n):
            x=(A*x+B)%M
            y=(C*y+D)%M
            points.append((x,y))
        case = (n,points)
        cases.append(case)
    return cases

case_number = 1
for case in readdata():
    n,points = case
    triangles = 0
    for p1 in xrange(n):
        v1 = points[p1]
        for p2 in xrange(p1 + 1, n):
            v2 = points[p2]
            for p3 in xrange(p2 + 1, n):
                v3 = points[p3]
                cx = (v1[0] + v2[0] + v3[0]) % 3
                cy = (v1[1] + v2[1] + v3[1]) % 3
                if cx == 0 and cy == 0:
                    triangles +=1
    print 'Case #' + str(case_number) + ':',triangles
    case_number += 1
