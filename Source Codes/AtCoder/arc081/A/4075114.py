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
As = map(int, input().split())
c = Counter(As)

ans = []
for k in reversed(sorted(c.keys())):
    v = c[k]
    while v >= 2:
        ans.append(k)
        v -= 2
        if len(ans) == 2:
            print(ans[0] * ans[1])
            sys.exit(0)
print(0)