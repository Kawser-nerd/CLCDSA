#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Feb 10 10:05:08 2019

@author: shinjisu
"""


# ARC 073 C
def getInt(): return int(input())


def getIntLines(n): return [int(input()) for i in range(n)]


def zeros(n): return [0]*n


def genBits(n):  # n??0/1????????[0]????
    bits = zeros(n)
    for i in range(2**n):
        for k in range(n):
            bits[k] = i % 2
            i //= 2
        yield bits


def dmp(x):
    global debug
    if debug:
        print(x)


def probC_TLE():
    N = getInt()
    S = getIntLines(N)
    dmp((N, S))
    maxPoint = 0
    for bit in genBits(N):
        point = 0
        for i in range(N):
            point += S[i]*bit[i]
        if point % 10 == 0:
            point = 0
        maxPoint = max(point, maxPoint)
        dmp((point, maxPoint))
    return maxPoint


def probC():
    N = getInt()
    S = getIntLines(N)
    dmp((N, S))
    tens = []
    nonTens = []
    for i in range(N):
        if S[i] % 10 == 0:
            tens.append(S[i])
        else:
            nonTens.append(S[i])
    total = sum(nonTens)
    dmp(total)
    if total > 0 and total % 10 == 0:
        total -= min(nonTens)
    dmp(total)
    if total > 0:
        total += sum(tens)
    dmp(total)
    return total


debug = False
print(probC())