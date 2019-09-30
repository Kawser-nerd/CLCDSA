#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Feb 10 10:05:08 2019

@author: shinjisu
"""


# ARC 076 C
import math


def getInt(): return int(input())


def getIntList(): return [int(x) for x in input().split()]


def dmp(x):
    global debug
    if debug:
        print(x)


def probC():
    N, M = getIntList()
    N1097 = 10**9 + 7
    dmp((N, M))
    if N == M:
        times = 2
    elif abs(N-M) == 1:
        times = 1
    else:
        times = 0
    dmp(times)
    # if times > 0:
    count = math.factorial(N) * math.factorial(M) * times % N1097
    return count


debug = False
print(probC())