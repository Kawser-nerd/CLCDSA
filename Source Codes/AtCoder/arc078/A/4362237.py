#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on 2019/2/
Solved on 2019/2/
@author: shinjisu
"""


# ARC 078 C  Splitting Pile
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
N1097 = 10**9 + 7


def dmp(x, cmt=''):
    global debug
    if debug:
        if cmt != '':
            print(cmt, ':  ', end='')
        print(x)
    return x


def probC():
    N = getInt()
    A = getIntList()
    dmp((N, A))
    sumFormer = A[0]
    sumLatter = sum(A[1:])
    diff = abs(sumFormer-sumLatter)
    dmp(diff,'init')
    for i in range(1, N-1):
        sumFormer += A[i]
        sumLatter -= A[i]
        diff = min(diff, abs(sumFormer-sumLatter))
    return diff


def probC_v1():  # 5/16 AC ???TLE
    N = getInt()
    A = getIntList()
    dmp((N, A))
    diff = 10**(9+6)
    for i in range(1, N):
        diff = min(diff, abs(sum(A[:i])-sum(A[i:])))
    return diff


debug = False  # True False
ans = probC()
print(ans)
#for row in ans:
#    print(row)