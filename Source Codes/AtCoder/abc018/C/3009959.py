from collections import defaultdict,deque
import sys,heapq,bisect,math,itertools,string,queue,datetime
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
def inpl(): return list(map(int, input().split()))
def inpl_s(): return list(input().split())

H,W,K = inpl()
K -= 1
MAP = [list(input()) for i in range(H)]
MAP2 = [[0]*(W+2*K+1) for i in range(H)]

def Update(sx,sy):
	global MAP2

	for y in range(sy-K,sy+K+1):
		if not(0 <= y < H):
			continue
		L = K - abs(sy-y)
		lx = sx-L
		rx = sx+L+1
		MAP2[y][lx+K] += 1
		MAP2[y][rx+K] -= 1

for y in range(H):
	for x in range(W):
		if MAP[y][x] == 'x':
			Update(x,y)

ans = 0
for y in range(H):
	tmp = 0
	for x in range(W+2*K+1):
		tmp += MAP2[y][x]
		MAP2[y][x] = tmp
		if tmp == 0 and K<=y<H-K and K*2<=x<W:
			ans += 1

print(ans)