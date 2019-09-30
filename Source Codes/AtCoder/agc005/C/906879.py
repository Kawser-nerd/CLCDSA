#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from collections import Counter

pos = "Possible"
imp = "Impossible"
def judge(nums):
    N = len(nums)
    count = Counter(nums)
    mx = max(nums)

    if mx == 1:
        if N == 2:
            return pos
        else:
            return imp
    elif mx == 2:
        if count[1] == 1 and count[2] >= 2:
            return pos
        else:
            return imp
    else:
        mid = (mx + 1) // 2

        for i in range(1, mid):
            if count[i] != 0:
                return imp
        if mx % 2 == 1:
            if count[mid] != 2:
                return imp
        else:
            if count[mid] != 1:
                return imp

        for i in range(mid+1, mx+1):
            if count[i] < 2:
                return imp

        return pos
                
dummy = int(input())
nums = list(map(int,input().split()))
print(judge(nums))


def mk(array):
    ret = []
    n = 1
    for e in array:
        ret += [n] * e
        n += 1
    print(ret)
    return ret