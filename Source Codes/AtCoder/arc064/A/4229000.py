#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Feb 11 09:54:00 2019

@author: shinjisu
"""


# ARC 064 WA
def getInt(): return int(input())


def getIntList(): return [int(x) for x in input().split()]


def dmp(x):
    global debug
    if debug:
        print(x)


def probC_try1():
    N, x = getIntList()
    a = getIntList()
    dmp((N, x, a))
    eatCnt = 0
    half = (x+1) // 2
    dmp((N,x,a,half))
    for i in range(N-1):
        if a[i]+a[i+1] > x:
            #eat = a[i]+a[i+1]-(min(a[i],half)+min(a[i+1],half))
            eat = a[i] - min(a[i],max(a[i+1]-half,half),half)
            eatCnt += eat
            a[i] = min(a[i],max(a[i+1]-half,half),half)
    eat = a[N-1] - min(a[N-1], half)
    eatCnt += eat
    a[N-1] = min(a[N-1],half)
    dmp((eatCnt,a))
    i=0
    while i<N:
        while i<N-1 and a[i]+a[i+1]<=x: i+=1
        cnt=1
        while i<N-1 and a[i]+a[i+1]>x: 
            i+=1; cnt+=1
        eatCnt += cnt//2
        dmp((cnt,eatCnt))
        i+=1
    return eatCnt


def probC():
    N, X = getIntList()
    a = getIntList()
    dmp((N, X, a))
    eatCnt = 0
    for i in range(N-1):
        dmp((eatCnt,a))
        if a[i] > X:
            eat = a[i] - X
            dmp(('eat',eat))
            eatCnt += eat
            a[i] = X
        if a[i]+a[i+1] > X:
            eat = a[i]+a[i+1] - X
            dmp(('eat',eat))
            eatCnt += eat
            if a[i+1] < eat:
                # a[i] -= X-a[i+1]
                a[i+1] = 0
            else:
                a[i+1] -= eat
    dmp((eatCnt,a))
    return eatCnt


debug = False  # True False
print(probC())