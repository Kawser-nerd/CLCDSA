from collections import defaultdict
import sys,heapq,bisect,math,itertools,string
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
AtoZ = [chr(i) for i in range(65,65+26)]
atoz = [chr(i) for i in range(97,97+26)]


N,M = map(int,input().split())

tb = [0]*(N+2)
STs = []


for i in range(M):
	s,t = map(int,input().split())
	STs.append([s,t])
	tb[s] += 1
	tb[t+1] -= 1

SUM = 0
for i in range(N+2):
	SUM += tb[i]
	tb[i] = SUM
	
SUM = 0
for i in range(N+2):
	if tb[i] == 1:
		SUM += 1
	tb[i] = SUM


ans = []
for i,[s,t] in enumerate(STs):
	if tb[t]-tb[s-1] == 0:
		ans.append(i)

print(len(ans))
for a in ans:
	print(a+1)