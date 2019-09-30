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
    (n, k) = readline().split()
    power = 2**int(n)
    if (int(k) + 1) % power == 0:
        print "Case #%d: ON" % (curcase)
    else:
        print "Case #%d: OFF" % (curcase)
