import sys, re
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

SA = list(input())
SB = list(input())
SC = list(input())
S = {"a":SA, "b":SB, "c":SC}
turn = "a"
while 1:
	if len(S[turn]) == 0:
		break
	turn = S[turn].pop(0)
print(turn.upper())