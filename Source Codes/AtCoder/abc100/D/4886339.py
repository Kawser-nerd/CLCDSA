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

N, M = MAP()
xyz = [LIST() for _ in range(N)]
ans = []
for i in range(0, 2):
	for j in range(0, 2):
		for k in range(0, 2):
			if i == 0:
				k_x = 1
			else:
				k_x = -1
			if j == 0:
				k_y = 1
			else:
				k_y = -1
			if k == 0:
				k_z = 1
			else:
				k_z = -1
			tmp = [x*k_x+y*k_y+z*k_z for x, y, z in xyz]
			tmp.sort(reverse=True)
			ans.append(sum(tmp[0:M]))
print(max(ans))