from collections import defaultdict,deque
import sys,heapq,bisect,math,itertools,string,queue,datetime
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
def inpl(): return list(map(int, input().split()))
def inpl_s(): return list(input().split())

N,M = inpl()
aa = inpl()
for i in range(N):
	aa[i] -= 1

yama_height = [0]*(2*M)
yama_num = [0]*(2*M)
SUM = 0
for i in range(1,N):
	na = aa[i]
	ba = aa[i-1]
	if na < ba:
		na += M
	SUM += (na-ba)
	yama_height[na] += na - (ba + 1)
	yama_num[na] -= 1
	yama_num[ba+1] += 1

tmp = 0
for i in range(2*M):
	tmp += yama_num[i]
	yama_num[i] = tmp

ans_list = [0]*(M)
tmp = 0
for i in reversed(range(2*M)):
	tmp += yama_height[i]
	tmp -= yama_num[i]
	ans_list[i%M] += tmp

print(SUM-max(ans_list))