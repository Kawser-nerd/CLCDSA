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

i, o, t, j, l, s, z = map(int, input().split())

ans = o

# a: xoooo.
#    xxx...
# b: xooo
#    xxxo
# c: xxxo
#    xooo
# d: oooo
#    xxxx

odd_num = (i % 2) + (j % 2) + (l % 2)
if odd_num >= 2 and i > 0 and j > 0 and l > 0:
    ans += 3
    i -= 1
    j -= 1
    l -= 1
ans += (i // 2) * 2
ans += (j // 2) * 2
ans += (l // 2) * 2
print(ans)