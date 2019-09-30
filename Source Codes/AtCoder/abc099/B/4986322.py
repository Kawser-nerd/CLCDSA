import sys
import re
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians
from itertools import permutations, combinations, product
from operator import itemgetter, mul
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase, digits


def input(): return sys.stdin.readline().strip()


def INT(): return int(input())


def MAP(): return map(int, input().split())


def LIST(): return list(map(int, input().split()))


sys.setrecursionlimit(10 ** 9)
INF = float('inf')
MOD = 10 ** 9 + 7

a, b = MAP()

for x in range(2, 1000):
    if b - a == x:
        print(int((x - 1) * x / 2 - a))