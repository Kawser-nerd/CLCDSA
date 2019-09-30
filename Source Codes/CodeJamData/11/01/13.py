#!/usr/bin/env python

import sys

def a():
    t = int(sys.stdin.readline())
    for i in xrange(t):
        line = sys.stdin.readline().split()
        n = int(line[0])
        o = 1
        b = 1
        otime = 0
        btime = 0
        prev = None
        for j in xrange(n):
            color,button = line[1 + 2*j: 3 + 2*j]
            button = int(button)
            if color == "O":
                diff = abs(button - o) + 1
                if prev == "B":
                    otime = max(btime + 1, otime + diff)
                else:
                    otime += diff
                o = button
            else:
                diff = abs(button - b) + 1
                if prev == "O":
                    btime = max(otime + 1, btime + diff)
                else:
                    btime += diff
                b = button
            prev = color
        print "Case #%d: %d" % (i + 1, max(otime, btime))

a()
        
