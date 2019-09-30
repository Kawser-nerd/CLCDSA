#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Feb  9 14:32:30 2019

@author: shinjisu
"""


# arc 072 c sequence
def getInt(): return int(input())


def getIntList(): return [int(x) for x in input().split()]


def db(x):
    global debug
    if debug:
        print(x)


def count(N, A, initSum):
    # global N, A
    sm = initSum
    cnt = abs(sm-A[0])
    db(cnt)
    for i in range(N-1):
        nextSum = sm + A[i+1]
        db((sm, nextSum))
        if sm > 0 and nextSum >= 0:
            cnt += abs(nextSum)+1
            sm = -1
        elif sm < 0 and nextSum <= 0:
            cnt += abs(nextSum)+1
            sm = 1
        else:
            sm = nextSum
        db(cnt)
    return cnt


def probC():
    N = getInt()
    A = getIntList()
    db((N, A))
    if A[0] != 0:
        initSum = A[0]
    else:
        initSum = 1
    cnt1 = count(N, A, initSum)
    db(('a[0] or +1: ', cnt1))
    if initSum > 0:
        cnt2 = count(N, A, -1)
    else:
        cnt2 = count(N, A, 1)
    db(('???? or -1: ', cnt2))
    return min(cnt1, cnt2)


debug = False
print(probC())