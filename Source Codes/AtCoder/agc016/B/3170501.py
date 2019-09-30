from collections import defaultdict,deque
import sys,heapq,bisect,math,itertools,string,queue,datetime
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
def inpl(): return list(map(int, input().split()))
def inpls(): return list(input().split())

N = int(input())
aa = inpl()
MIN = min(aa)
MAX = max(aa)

if MAX-MIN > 1:
	print('No')
elif MAX == MIN:
	if MAX == N-1:
		print('Yes')
	elif MAX <= N//2:
		print('Yes')
	else:
		print('No')
else: #MAX-MIN == 1
	n_MIN = n_MAX = 0
	for a in aa:
		if a == MIN: n_MIN += 1
		if a == MAX: n_MAX += 1
	x_min = n_MIN + 1
	x_max = n_MIN + n_MAX//2
	if x_min <= MAX <= x_max:
		print('Yes')
	else:
		print('No')