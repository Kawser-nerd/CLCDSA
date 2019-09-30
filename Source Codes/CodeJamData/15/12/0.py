for cas in xrange(1,1+input()):
	b, n = map(int, raw_input().strip().split())
	n -= 1
	m = map(int, raw_input().strip().split())
	def f(T):
		s = 0
		for i in xrange(b):
			s += (T + m[i]-1) / m[i]
		return s
	L = 0
	R = 10**50
	while  R - L > 1:
		M = L + R >> 1
		fM = f(M)
		if fM > n:
			R = M
		else:
			L = M

	# now f(L) <= n < f(R)
	dist = [0]*b
	for i in xrange(b):
		ct = (L + m[i] - 1) / m[i]
		dist[i] = ct * m[i]
		n -= ct
	assert 0 <= n < b
	idxs = sorted(range(b), key=lambda i: (dist[i], i))

	print "Case #%s: %s" % (cas, idxs[n]+1)
