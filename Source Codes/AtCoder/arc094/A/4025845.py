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

nums = list(map(int, input().split()))

nums.sort()

ans = 0
while nums[0] != nums[-1]:
    if nums[0] < nums[1]:
        nums[0] += 2
    else:
        nums[0] += 1
        nums[1] += 1
    ans += 1
    nums.sort()
print(ans)