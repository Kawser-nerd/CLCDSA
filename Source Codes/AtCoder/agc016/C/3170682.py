from collections import defaultdict,deque
import sys,heapq,bisect,math,itertools,string,queue,datetime
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
def inpl(): return list(map(int, input().split()))
def inpls(): return list(input().split())

H,W,h,w = inpl()
MAP = [[0]*W for i in range(H)]

pl = mn = 0
tmp = 0
for y in range(H):
	for x in range(W):
		if (y+1)%h==0 and (x+1)%w==0:
			MAP[y][x] -= (h*w-1)*1000 +1
			mn += 1
			tmp -= (h*w-1)*1000 +1
		else:
			MAP[y][x] = 1000
			pl += 1
			tmp += 1000

if tmp <= 0:
	print('No')
else:
	print('Yes')
	for m in MAP:
		print(' '.join(map(str,m)))