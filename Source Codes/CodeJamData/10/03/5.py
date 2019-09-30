#!/usr/bin/env python
# -*- coding: utf-8 -*-

# (c) DDPAlphaTiger1 2009
# Will be under GPL after the end of GCJ
# Under no-use-by-anyone-else-than-me license until then :D
# ***** *****
# Thanks for reading my weird code !
# ***** *****
# Note : I have a wiiide screen, that helps ...

import sys

import psyco
psyco.full()

def readline():
    return sys.stdin.readline()[:-1]

def readnlines(n):
    l = []
    for i in range(n):
        l.append(readline())

for curcase in range(1, int(readline())+1):
    (r, k, n) = readline().split()
    r = int(r)
    k = int(k)
    n = int(n)

    l = map(int, readline().split())

    comp = [(-1,0)] * n

    begin = 0
    cur = 0
    beginlst = []
    total = 0
    while True:
        begin = cur
        curtotal = 0
        if comp[begin] == (-1, 0):
            beginlst.append(begin)
            while curtotal + l[cur] <= k:
                curtotal += l[cur]
                cur = (cur + 1) % n
                if cur == begin:
                    break
            comp[begin] = (curtotal, cur)
            total += curtotal
            r -= 1
            if r == 0:
                break
        else:
            loop = beginlst[beginlst.index(begin):]
            total += (r / len(loop)) * sum(map(lambda (x, y): x, map(lambda x: comp[x], loop)))
            r = r % len(loop)
            for i in range(0, r):
                (x, y) = comp[loop[i]]
                total += x
            break

    print "Case #%d: %d" % (curcase, total)
