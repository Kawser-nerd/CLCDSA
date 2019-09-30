#!/usr/bin/python2
# -*- coding: utf-8 -*-

import sys
import os

LEFT, TOP, RIGHT, BOT = range(4)

dest = [[0, -1], [-1, 0], [0, 1], [1, 0]]

def translate(v, R, C):
    v -= 1
    if v < C:
        return (0, v, TOP)
    v -= C
    if v < R:
        return (v, C-1, RIGHT)
    v -= R
    if v < C:
        return (R-1, C-v-1, BOT)
    v -= C
    return (R-v-1, 0, LEFT)

def flow(pos, m, R, C):
    r = pos[0]
    c = pos[1]
    pp = pos[2]
    #print "flow", pos
    #print_mask(m, R, C)
    while 0 <= r < R and 0 <= c < C:
        v = m & (1 << (r*C + c))
        if v:
            pp = pp ^ 1
        else:
            pp = 3 - pp
        r += dest[pp][0]
        c += dest[pp][1]
        pp ^= 2
    if r < 0:
        return (0, c, TOP)
    elif c < 0:
        return (r, 0, LEFT)
    elif r >= R:
        return (R-1, c, BOT)
    else:
        return (r, C-1, RIGHT)


def print_mask(m, R, C):
    for i in xrange(R):
        s = ""
        for j in xrange(C):
            if m & (1 << (i*C + j)):
                s += "/"
            else:
                s += "\\"
        print s


def main():
    T = int(sys.stdin.readline())
    for t in xrange(1, T+1):
        R, C = map(int, sys.stdin.readline().split())
        A = map(int, sys.stdin.readline().split())
        print "Case #%s:" % (t,)
        for m in xrange(1 << (R*C)):
            #print_mask(m, R, C)
            good = True
            maze = []
            for i in xrange(R):
                maze.append([[None] * 4 for _ in xrange(C)])
            for i in xrange(0, len(A), 2):
                #print i
                ret = flow(translate(A[i], R, C), m, R, C)
                if ret != translate(A[i+1], R, C):
                    good = False
                    break
            if good:
                print_mask(m, R, C)
                break
        else:
            print "IMPOSSIBLE"


if __name__ == '__main__':
    main()
