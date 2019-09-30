#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Feb 10 10:05:08 2019

@author: shinjisu
"""


# ARC 077 C
def getInt(): return int(input())


def getIntList(): return [int(x) for x in input().split()]


def zeros(n): return [0]*n


def dmp(x):
    global debug
    if debug:
        print(x)


def probC_TLE():
    N = getInt()
    A = getIntList()
    dmp((N, A))
    b = []
    for i in range(N):
        b.append(A[i])
        b.reverse()
        dmp(b)
    return b


def probC_TLE2():
    N = getInt()
    A = getIntList()
    dmp((N, A))
    former, latter = [], []
    for i in range(-1, -N-1, -1):
        if i % 2 == 0:
            latter = [A[i]] + latter
        else:
            former.append(A[i])
        full = former + latter
        dmp((former, latter, full))
    return full


def probC_TLE3():
    N = getInt()
    A = [x for x in input().split()]
    dmp((N, A))
    former, latter = '', ''
    for i in range(-1, -N-1, -1):
        if i % 2 == 0:
            latter = A[i] + ' ' + latter
        else:
            former = former + ' ' + A[i]
        dmp((former, latter))
    return former[1:] + ' ' + latter


def probC():
    N = getInt()
    A = getIntList()
    dmp((N, A))
    b = zeros(N)
    for i in range(-1, -N-1, -1):
        if i % 2 == 0:
            b[i//2] = A[i]
        else:
            b[-i//2] = A[i]
        dmp(b)
    return b


debug = False
# print(probC())
for n in probC():
    print(n, end=' ', flush=True)