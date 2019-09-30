from collections import defaultdict,deque
import sys,heapq,bisect,math,itertools,string,queue,datetime
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
def inpl(): return list(map(int, input().split()))
def inpl_s(): return list(input().split())


N = int(input())
aa = inpl()

b = 1
for a in aa:
	b |= b << a

S = sum(aa)
half = (S+1)//2
b >>= half

print((b&-b).bit_length()+half-1)