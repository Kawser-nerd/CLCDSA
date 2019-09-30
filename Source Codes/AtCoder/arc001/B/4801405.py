# -*- coding: utf-8 -*-

# from collections import *
import sys
import copy

#input = sys.stdin.readline

# ---------------------------------------------------------

N = int(input())
S = input()

cnt = [0] * 4

for x in S:
    cnt[int(x) - 1] += 1

print(max(cnt), min(cnt))