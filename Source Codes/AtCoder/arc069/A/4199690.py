#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Feb  9 10:45:37 2019

@author: shinjisu
"""
# arc 069 Scc puzzle


def getIntList(): return [int(x) for x in input().split()]


def db(x):
    global debug
    if debug:
        print(x)


def solve():
    if N >= M//2:
        return M//2
    return N + (M-N*2)//4


debug = False
N, M = getIntList()
db((N, M))
print(solve())