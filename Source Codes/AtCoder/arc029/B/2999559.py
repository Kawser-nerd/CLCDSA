from collections import defaultdict
import sys,heapq,bisect,math,itertools,string,queue,datetime
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
PI = math.pi
AtoZ = [chr(i) for i in range(65,65+26)]
atoz = [chr(i) for i in range(97,97+26)]

def inpl(): return list(map(int, input().split()))
def inpl_s(): return list(input().split())

A,B = inpl()
A,B = min(A,B),max(A,B)
N = int(input())
phi = math.atan(A/B)
r = math.sqrt(A**2+B**2)

for i in range(N):
	C,D = inpl()
	C,D = min(C,D),max(C,D)
	if A<=C and B<=D:
		print('YES')
	elif C < A and B < D:
		print('NO')
	else:
		OK = 0
		NG = PI-phi
		for _ in range(100):
			mid = (OK+NG)/2
			h = r*math.sin(mid+phi)
			if h <= D: OK = mid
			else: NG = mid

		w = r*math.cos(OK-phi)
		if w <= C:
			print('YES')
		else:
			print('NO')