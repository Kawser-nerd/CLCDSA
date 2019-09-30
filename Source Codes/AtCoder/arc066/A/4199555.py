#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Feb  9 09:53:28 2019

@author: shinjisu
"""


# ARC 066 C lining up
def getInt(): return int(input())


def getIntList(): return [int(x) for x in input().split()]


def db(x):
    global debug
    if debug:
        print(x)


def solve():
    A.sort()
    db(A)
    if A[0] == 0:
        n = 1
    else:
        n = 0
    for i in range(n, len(A), 2):
        db(i)
        if A[i] != A[i+1]:
            return 0
    return 2**(len(A)//2) % (10**9+7)


debug = False
N = getInt()
A = getIntList()
db((N, A))
print(solve())