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

N, T = map(int, input().split())

prev = None
ans = 0
for t in map(int, input().split()):
    if prev is not None:
        if t - prev < T:
            ans += t - prev
        else:
            ans += T
    prev = t
ans += T
print(ans)