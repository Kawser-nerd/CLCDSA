#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# N = 50????????
# K = 151???????3???????2????????????????
# ?????????98???????
# ??????99?????????????
# ??????????????????

import array
from bisect import *
from collections import *
import fractions
import heapq 
from itertools import *
import math
import random
import re
import string
import sys
import numpy as np

def solve_d(k):
    if k == 0:
        return [0] * 50

    if k <= 50:
        arr = []
        for i in range(k):
            arr.append(50 - i)
        for i in range(k, 50):
            arr.append(0)
        return arr
    else:
        arr = list(reversed(range(1, 51)))
        base = (k - 1) // 50
        for i in range(50):
            arr[i] += base - 1
        for i in range(k - base * 50):
            arr[i] += 1
        return arr

K = int(input())
print(50)
print(*solve_d(K))


##################
# ????????
##################

# ??E????
def solve_e(As):
    ans = 0
    N = len(As)
    As = As[:]
    while True:
        taken = [0] * N
        for i, a in enumerate(As):
            taken[i] = a // N
            As[i] -= taken[i] * N
        taken_sum = sum(taken)
        if taken_sum == 0:
            break
        ans += taken_sum
        for i in range(N):
            As[i] += (taken_sum - taken[i])
    return ans

# # ??(E????????)
# for k in range(1000):
#     arr = solve_d(k)
#     arr_copied = arr.copy()
#     res = solve_e(arr_copied)
#     print("====\nk = ", k)
#     print("arr: ", arr)
#     if res != k:
#         print("error! res = ", res)
#         break