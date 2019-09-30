import math
import itertools
import heapq
from sys import stdin, stdout, setrecursionlimit
from bisect import bisect, bisect_left, bisect_right
from collections import defaultdict, deque


# d = defaultdict(lambda: 0)
# setrecursionlimit(10**7)
# inf = float("inf")


##### stdin ####
def LM(t, r): return list(map(t, r))
def R(): return stdin.readline()
def RS(): return R().split()
def I(): return int(R())
def F(): return float(R())
def LI(): return LM(int,RS())
def LF(): return LM(float,RS())
def ONE_SL(): return list(input())
def ONE_IL(): return LM(int, ONE_SL())
def ALL_I(): return map(int, stdin)
def ALL_IL(): return LM(int,stdin)

##### tools #####
def ap(f): return f.append
def pll(li): print('\n'.join(LM(str,li)))
def pljoin(li, s): print(s.join(li))



##### main #####
def main():
	N = I()
	X = LI()
	L = I()
	Q = I()
	

	r = [[0 for _ in range(100010)] for _ in range(20)]

	for i in range(N):
		r[0][i] = bisect_right(X, X[i]+L) -1

	for i in range(1,20):
		for j in range(N):
			r[i][j] = r[i-1][r[i-1][j]]


	for q in range(Q):
		a,b =LI()
		a-=1; b-=1

		if a>b: a,b = b,a
		
		ans = 0
		now = a
		for i in range(0,20)[::-1]:
			if r[i][now]<b:
				now = r[i][now]
				ans += 2**i
		print(ans+1)



if __name__ == '__main__':
	main()