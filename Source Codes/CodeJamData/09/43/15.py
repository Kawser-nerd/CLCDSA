from itertools import *

T = int(input())
for t in range(1,T+1):
	
	N,K = (int(s) for s in input().split())
	stocks = [tuple(int(s) for s in input().split()) for _ in  range(N)]
	
	def intersect(a,b):
		def ints(*args):
			(a,b),(c,d) = args
			return not(a < c and b < d or a > c and b > d)
		return any(ints(*s) for s in zip(zip(a[:-1], a[1:]), zip(b[:-1],b[1:])))
	
	ints = [[s] for s in stocks]
	for s in stocks:
		ints += [i + [s] for i in ints if all(intersect(s, _i) for _i in i)]
	
	print('Case #%s: %s' % (t, max(len(i) for i in ints) - 1))
