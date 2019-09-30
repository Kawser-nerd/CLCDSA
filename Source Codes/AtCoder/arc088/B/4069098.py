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

S = input()
size = len(S)
if len(S) % 2 == 0:
    ans = size // 2
    base = S[size // 2]
    for i in range(size // 2):
        if S[size // 2 - 1 - i] == S[size // 2 + i] == base:
            ans += 1
        else:
            break
    print(ans)
else:
    ans = size // 2 + 1
    base = S[size // 2]
    for i in range(size // 2):
        if S[size // 2 - 1 - i] == S[size // 2 + 1 + i] == base:
            ans += 1
        else:
            break
    print(ans)