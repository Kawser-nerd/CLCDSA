#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on 2019/2/
Solved on 2019/2/
@author: shinjisu
"""


# ARC 062 C AtCoDeer and Rock-Paper
def getInt(): return int(input())


def getIntList(): return [int(x) for x in input().split()]


def zeros(n): return [0]*n


def getIntLines(n): return [int(input()) for i in range(n)]


def getIntMat(n):
    mat = []
    for i in range(n):
        mat.append(getIntList())
    return mat


def zeros2(n, m): return [zeros(m)]*n


ALPHABET = [chr(i+ord('a')) for i in range(26)]
DIGIT = [chr(i+ord('0')) for i in range(10)]


def dmp(x, cmt=''):
    global debug
    if debug:
        if cmt != '':
            print(cmt, ':  ', end='')
        print(x)
    return x


def probC():
    S = input()
    dmp(S)
    GU = 'g'
    PA = 'p'
    guCount = 0
    paCount = 0
    point = 0
    allTe = ''
    for i in range(len(S)):
        if paCount < guCount:
            te = PA
            paCount += 1
        else:
            te = GU
            guCount += 1

        if te == GU and S[i] == PA:
            point -= 1
        elif te == PA and S[i] == GU:
            point += 1
        allTe += te
    dmp(allTe,'allTe')
    dmp(point)
    return point


debug = False  # True False
ans = probC()
print(ans)
#for row in ans:
#    print(row)

"""
        if S[i] == GU:
            if paCount < guCount:
                te = PA
                paCount += 1
            else:
                te = GU
                guCount += 1
        else:
            if paCount < guCount:
                te = PA
                paCount += 1
            else:
                te = GU
                guCount += 1
"""