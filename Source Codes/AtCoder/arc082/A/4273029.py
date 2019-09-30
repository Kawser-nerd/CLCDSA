#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Feb 10 10:05:08 2019

@author: shinjisu
"""


# ARC 076 C
def getInt(): return int(input())


def getIntList(): return [int(x) for x in input().split()]


def zeros(n): return [0]*n


def dmp(x):
    global debug
    if debug:
        print(x)
    return x


def probC():
    N = getInt()
    A = getIntList()
    dmp((N, A))
    maxA = max(A)
    dmp(maxA)
    b = zeros(maxA+3)
    for i in range(N):
        b[A[i]] += 1
        b[A[i]+1] += 1
        b[A[i]+2] += 1
    dmp(b)
    return dmp(max(b))


debug = False  # True False
print(probC())

def probCTLE2():
    N = getInt()
    A = getIntList()
    dmp((N, A))
    hist = zeros(10**5)
    for i in range(N):
        if A[i] in hist:
            hist[A[i]] += 1
        else:
            hist[A[i]] = 1
    #dmp(hist)
    mxCnt = 1
    #keylist = list(hist.keys())
    #mxKey = max(keylist)
    # dmp(mxKey)
    for k in range(10**5-2):
        cnt = hist[k] + hist[k+1] + hist[k+2]
        mxCnt = max(mxCnt, cnt)
    return mxCnt


def probCTLE():
    N = getInt()
    A = getIntList()
    dmp((N, A))
    hist = {}
    for i in range(N):
        if A[i] in hist:
            hist[A[i]] += 1
        else:
            hist[A[i]] = 1
    dmp(hist)
    mxCnt = 1
    keylist = list(hist.keys())
    mxKey = max(keylist)
    dmp(mxKey)
    for k in hist.keys():
        cnt = 0
        if k-1 in keylist:
            cnt += hist[k-1]
        if k in keylist:
            cnt += hist[k]
        if k+1 in keylist:
            cnt += hist[k+1]
        mxCnt = max(mxCnt, cnt)
        dmp(('max',mxCnt))
    return mxCnt


def probCWA():
    N = getInt()
    A = getIntList()
    dmp((N, A))
    hist = {}
    for i in range(N):
        if A[i] in hist:
            hist[A[i]] += 1
        else:
            hist[A[i]] = 1
    dmp(hist)
    mxCnt = 1
    keylist = list(hist.keys())
    mxKey = max(keylist)
    dmp(mxKey)
    for i in range(mxKey-1):
        cnt = 0
        if i in keylist:
            cnt += hist[i]
        if i+1 in keylist:
            cnt += hist[i+1]
        if i+2 in keylist:
            cnt += hist[i+2]
        mxCnt = max(mxCnt, cnt)
        dmp(('max',mxCnt))
    return mxCnt