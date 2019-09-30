#!/usr/bin/env python
#coding: utf-8

from sys import stdin, stderr
from math import log10


def solve(human):
    time1 = []
    time2 = []
    for h in human:
        t = (360. - h[0]) / 360. * h[1]
        time1.append(t)
        time2.append(t+h[1])
        pass
    if max(time1) < min(time2): return 0
    return 1



T = int(stdin.readline())
for t in range(T):
    human = []
    N = int(stdin.readline())
    for n in range(N):
        D, H, M = (int(wd) for wd in stdin.readline().split())
        for h in range(H): human.append([D, M+h])
    print "Case #%i:" % (t+1),
    #print R, C, N,
    print solve(human)
