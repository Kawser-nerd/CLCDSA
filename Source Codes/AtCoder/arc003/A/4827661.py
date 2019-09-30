# -*- coding: utf-8 -*-

import sys
import copy

input = sys.stdin.readline

# ---------------------------------------------------------

N = int(input())
r = input().rstrip()

sum = 0
sum += r.count('A') * 4
sum += r.count('B') * 3
sum += r.count('C') * 2
sum += r.count('D') * 1

print(sum / N)