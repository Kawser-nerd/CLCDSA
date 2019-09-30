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
	ss = input().split('T')
	x, y = map(int, input().split())
	 
	dpx = dict()
	dpy = dict()
	 
	dpx[0+len(ss[0])] = True
	dpy[0] = True
	 
	direct = 1 #0:x, 1:y
	 
	 
	for s in ss[1:]:
		tmp = dict()
		n = len(s)
		if direct%2 == 0: 
			for k, v in dpx.items():
				tmp[k+n] = True
				tmp[k-n] = True
			dpx = tmp
		else:
			for k, v in dpy.items():
				tmp[k+n] = True
				tmp[k-n] = True
			dpy = tmp

		# print(dpx, dpy)
		direct += 1
	 	

	if x in dpx and y in dpy:
	    print('Yes')
	else:
	    print('No')


if __name__ == '__main__':
	main()