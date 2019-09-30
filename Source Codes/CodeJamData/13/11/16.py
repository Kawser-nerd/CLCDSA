from math import pi
T = int(raw_input())

def fn(r, n):
	return (2*n*r + 2*(n*(n-1))+ n)

for z in xrange(1, T+1):
	r, t = [int(i) for i in raw_input().split()]
	
	lo = 0
	hi = 2**64
	while hi-lo > 1:
		mid = int((hi+lo)/2)
		val = fn(r, mid)
		if val < t:
			lo = mid
		elif val > t:
			hi = mid
		else:
			hi = mid
			lo = mid
			break
	ans = 0
	if fn(r, hi) > t:
		ans = lo
	else:
		ans = hi
	print "Case #%d: %d"%(z, ans)