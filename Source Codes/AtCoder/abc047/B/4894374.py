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

W, H, N = MAP()
xya = [LIST() for _ in range(N)]

right = W
left = 0
top = H
bottom = 0

for x, y, a in xya:
	if a == 1 and left < x < right:
		left = x
	elif a == 1 and right <= x:
		S = 0
		break
	elif a == 2 and left < x < right:
		right = x
	elif a == 2 and x <= left:
		S = 0
		break
	elif a == 3 and bottom < y < top:
		bottom = y
	elif a == 3 and top <= y:
		S = 0
		break
	elif a == 4 and bottom < y < top:
		top = y
	elif a == 4 and y <= bottom:
		S = 0
		break
	else:
		pass
	# print(left, right, top, bottom)
	S = (right-left)*(top-bottom)
if S <= 0:
	S = 0
print(S)