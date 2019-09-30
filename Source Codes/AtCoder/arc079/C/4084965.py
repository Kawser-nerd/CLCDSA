#!/usr/bin/env python3
# -*- coding: utf-8 -*-

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

N = int(input())
As = list(map(int, input().split()))

ans = 0
while True:
    taken = [0] * N
    for i, a in enumerate(As):
        taken[i] = a // N
        As[i] -= taken[i] * N
    # print("===")
    # print(As)
    # print(taken)

    taken_sum = sum(taken)
    if taken_sum == 0:
        break
    ans += taken_sum
    for i in range(N):
        As[i] += (taken_sum - taken[i])
print(ans)