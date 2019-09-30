# coding: utf-8
import sys
import heapq
import bisect
import operator
from itertools import *

import numpy as np

def read():
  return int(input())

def reads():
  return [int(s) for s in input().split()]

T = read()

dic = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
chars = sorted(set("".join(dic)))
R = len(chars)
M = np.array([[sum(chars[i] == c for c in dic[j]) for j in range(10)] for i in range(R)])

# Z → 0
# W → 2
# X → 6

for case in range(1, T+1):
  S = input()
  b = np.array([sum(chars[i] == c for c in S) for i in range(R)])
  sol = [int(x + 0.5) for x in np.linalg.lstsq(M, b)[0]]

  result = "".join(str(i) * sol[i] for i in range(10))
  print("Case #{0}: {1}".format(case, result))
