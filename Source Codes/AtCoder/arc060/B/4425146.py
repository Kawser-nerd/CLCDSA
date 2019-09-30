#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# ??PDF??????
#
# ?????????????2????????????
# ??????????????

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


def get_sum(base, n):
    nums = []
    while n > 0:
        nums.append(n % base)
        n //= base
    return sum(nums)


def solve(N, S):
    if S == N:
        return S + 1
    for base in range(2, int(math.sqrt(N)) + 2):
        if S == get_sum(base, N):
            return base
    for p in range(int(math.sqrt(N)) + 1, 0, -1):
        q = S - p
        if (N - q) % p == 0:
            base = (N - q) // p
            if base <= 1 or q < 0 or q >= base:
                continue
            return base
    return -1


N = int(input())
S = int(input())
print(solve(N, S))