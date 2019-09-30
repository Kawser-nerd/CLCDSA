def main():
	MOD = 100003
	f = []
	c = {}
	d = {}
	def fact(n):
		if not f:
			s = 1
			for i in xrange(1010):
				if i:
					s *= i
				f.append(s)

		if n<=1:
			return 1
		return f[n]

	def C(n,k):
		if (n,k) in c:
			return c[(n,k)]
		ret = c[(n,k)] = fact(n)/fact(k)/fact(n-k)%MOD
		return ret
	def D(n,k):
		if k == 1:
			return 1
		if n == k+1:
			return 1
		if (n,k) in d:
			return d[(n,k)]
		cnt = 0
		for i in xrange(1, k):
			cnt += D(k,i) * C(n-k-1, k-i-1)
			cnt %= MOD
		d[(n,k)] = cnt
		return cnt

	tn = int(raw_input())
	for i in xrange(1,500):
		for j in xrange(1,i):
			D(i,j)
		print i
	for loop in xrange(tn):
		n = int(raw_input())
		print 'Case #%d:' % (loop+1), sum(D(n,i) for i in xrange(1,n))%MOD

try:
	import psyco
	psyco.full()
except: pass

main()
