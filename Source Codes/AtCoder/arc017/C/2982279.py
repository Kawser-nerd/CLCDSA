from collections import defaultdict
import sys,heapq,bisect,math,itertools,string,queue,datetime
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
AtoZ = [chr(i) for i in range(65,65+26)]
atoz = [chr(i) for i in range(97,97+26)]

def inpl(): return list(map(int, input().split()))
def inpl_s(): return list(input().split())

N,X = inpl()
ww = [int(input()) for i in range(N)]
k = N//2
flags1 = itertools.product([0,1], repeat=k)
flags2 = itertools.product([0,1], repeat=N-k)

dd1 = defaultdict(int)
ed = []
dd2 = defaultdict(int)

for flag in flags1:
	tmp = 0
	for i,fl in enumerate(flag):
		if fl:
			tmp += ww[i]

	if dd1[tmp] == 0:
		ed.append(tmp)
	dd1[tmp] += 1

for flag in flags2:
	tmp = 0
	for i,fl in enumerate(flag):
		if fl:
			tmp += ww[i+k]
	dd2[tmp] += 1

ans = 0
for e in ed:
	ans += dd1[e]*dd2[X-e]

print(ans)