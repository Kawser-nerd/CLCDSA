cache = {}
A,B,K=0,0,0

def f(upto, abound, bbound, kbound):
	if upto >= len(A):
		return 1
	if (upto, abound, bbound, kbound) in cache:
		return cache[(upto, abound, bbound, kbound)]
	a = int(A[upto])
	b = int(B[upto])
	k = int(K[upto])
	ans = 0
	for ma in (0,1):
		for mb in (0,1):
			mk = ma&mb
			if abound and ma > a:
				continue
			if bbound and mb > b:
				continue
			if kbound and mk > k:
				continue
			ans += f(upto+1, abound and ma==a, bbound and mb==b, kbound and mk==k)
	cache[(upto, abound, bbound, kbound)] = ans
	return ans


def do():
	global A, B, K, cache
	cache = {}
	A, B, K = map(lambda x: bin(int(x)-1)[2:].zfill(100), raw_input().split())
	return str(f(0, True, True, True))

T = input()
for i in xrange(T):
	print "Case #%s: %s" % (i+1, do())
