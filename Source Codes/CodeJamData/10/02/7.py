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

#import psyco
#psyco.full()

def readline():
    return sys.stdin.readline()[:-1]

def readnlines(n):
    l = []
    for i in range(n):
        l.append(readline())

def gcd(a,b):
    if a >= b:
        m = a % b
        if m == 0:
            return b
        else:
            return gcd(b, m)
    else:
        return gcd(b, a)

def truc(x0, x):
    y = abs(x0 - x)
    if y == 0:
        return 1
    else:
        return y

for curcase in range(1, int(readline())+1):
    l = map(int, readline().split())
    n = l[0]
    l = l[1:]
    x0 = l[0]

    diff = map(lambda x: abs(x0 - x), l[1:])

    cur = diff[0]
    for i in range(1, len(diff)):
        if cur == 0:
            cur = diff[i]
        if diff[i] != 0:
            cur = gcd(cur, diff[i])

    todo = x0 % cur
    if todo == 0:
        print "Case #%d: %d" % (curcase, 0)
    else:
        print "Case #%d: %d" % (curcase, cur - todo)
