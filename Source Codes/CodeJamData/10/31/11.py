#!/usr/bin/env python

import sys

class Rope:
    def __init__(self,point1,point2):
        self.A = point1
        self.B = point2

    def intersects(self,rope):
        if ( ( self.A - rope.A ) * ( self.B - rope.B ) ) > 0:
            return False
        else:
            return True

def main(argv):
    n = int(sys.stdin.readline())
    for i in range(1,n+1):
        T = int(sys.stdin.readline())

        ropes = []
        intersects = 0
        for j in range(T):
            line = sys.stdin.readline().split(" ")
            thisRope = Rope(int(line[0]),int(line[1]))
            for otherRope in ropes:
                if thisRope.intersects(otherRope):
                    intersects += 1
            ropes.append(thisRope)

        print("Case #%d: %d" % (i, intersects))

main(sys.argv)
