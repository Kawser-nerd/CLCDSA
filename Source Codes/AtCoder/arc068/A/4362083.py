#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on 2019/2/24
Solved on 2019/2/
@author: shinjisu
"""


# ABC 076 C Explanation
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
    dmp(N)
    count = N // (5+6) * 2
    rem = N % (5+6)
    if rem > 6:
        count += 2
    elif rem > 0:
        count += 1
    return count


debug = False  # True False
ans = probC()
print(ans)
#for row in ans:
#    print(row)