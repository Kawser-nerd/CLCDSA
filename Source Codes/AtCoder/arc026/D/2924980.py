from collections import defaultdict
import sys,heapq,bisect,math,itertools,string
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-10
AtoZ = [chr(i) for i in range(65,65+26)]
atoz = [chr(i) for i in range(97,97+26)]

def inpl_int(): return list(map(int, input().split()))
def inpl_str(): return list(map(int, input().split()))

def check(x):
	salt = []
	for w,p in wp:
		salt.append((p-x)*w*0.01)
	salt.sort(reverse=True)
	return sum(salt[:K]) >= 0

def Find(x):	#x?????
	global table

	if table[x] == x:
		return x
	else:
		table[x] = Find(table[x])	#????(???????????????)
		return table[x]

def Union(x,y):	#x?y????
	x = Find(x)
	y = Find(y)

	if x == y:
		return

	if rank[x] > rank[y]:
		table[y] = x
	else:
		table[x] = y
		if rank[x] == rank[y]:
			rank[y] += 1

def Check(x,y):
	if Find(x) == Find(y):
		return True
	else:
		return False


N,M = inpl_int()

ABCTs = []

for i in range(M):
	a,b,c,t = inpl_int()
	ABCTs.append([a,b,c,t])

table = [i for i in range(N)]
rank  = [1 for i in range(N)]

def YUI(x):
	global table
	global rank

	table = [i for i in range(N)]
	rank  = [1 for i in range(N)]

	q = []
	heapq.heapify(q)
	weight = 0

	for a,b,c,t in ABCTs:
		w = x*t - c
		heapq.heappush(q,[-w,a,b])

	while q:
		w,a,b = heapq.heappop(q)
		w *= -1
		if not Check(a,b) or w>=0:
			weight += w
			Union(a,b)

	return weight >= 0

NG = 0
OK = 10**6 + 334

while OK-NG > eps:
	mid = (OK+NG)/2

	if YUI(mid):
		OK = mid
	else:
		NG = mid

print(OK)