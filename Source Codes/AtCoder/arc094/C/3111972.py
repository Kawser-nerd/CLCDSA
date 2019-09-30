from collections import defaultdict,deque
import sys,heapq,bisect,math,itertools,string,queue,datetime
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
def inp(): return int(input())
def inpl(): return list(map(int, input().split()))
def inpls(): return list(input().split())

N = inp()
tmp = INF
S = 0
for i in range(N):
	A,B = inpl()
	S += A
	if A > B:
		tmp = min(B,tmp)

if tmp == INF:
	print(0)
else:
	print(S-tmp)