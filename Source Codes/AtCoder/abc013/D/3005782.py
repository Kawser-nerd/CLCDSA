from collections import defaultdict,deque
import sys,heapq,bisect,math,itertools,string,queue,datetime
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
def inpl(): return list(map(int, input().split()))
def inpl_s(): return list(input().split())


N,M,D = inpl()
aa = inpl()
L = int(math.log2(D))+1

T = [[i for i in range(N)] for j in range(L)]

for a in reversed(aa):
	T[0][a-1],T[0][a] = T[0][a],T[0][a-1]

flags = []
for k in range(L):
	flags.append(D>>k & 1)

for k in range(1,L):
	for i in range(N):
		T[k][i] = T[k-1][T[k-1][i]]

for i in range(N):
	ans = i
	for k,flag in enumerate(flags):
		if flag:
			ans = T[k][ans]
	print(ans+1)