#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
??????????PDF?????
"""

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

A = input()
counter = Counter(A)

N = len(A)
ans = N * (N - 1) // 2 - sum(c * (c - 1) // 2 for c in counter.values()) + 1
print(ans)