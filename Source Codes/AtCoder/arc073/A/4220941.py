#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Feb 10 10:05:08 2019

@author: shinjisu
"""


# ARC 073 C
def getInt(): return int(input())


def getIntList(): return [int(x) for x in input().split()]


def dmp(x):
    global debug
    if debug:
        print(x)


def probC():
    N, T = getIntList()
    Ts = getIntList()
    dmp((N, T, Ts))
    total = Ts[0]
    for i in range(1, N):
        total += min(T, Ts[i]-Ts[i-1])
    return total+T


debug = False
print(probC())