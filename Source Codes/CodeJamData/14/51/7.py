cases = int(raw_input())

def getpt(d, s, m):
	s, t = s, len(d) - 1
	while s != t:
		v = (s + t + 1) >> 1
		if d[v] <= m:
			s = v
		else:
			t = v - 1
	return s, d[s]

for case in range(1, cases + 1):
	n, p, q, r, s = tuple([int(i) for i in raw_input().split()])
	num = []
	snm = [0]
	for i in xrange(n):
		num.append((i * p + q) % r + s)
		snm.append(snm[-1] + num[-1])

	s, t = 0, snm[n]
	while s != t:
		m = (s + t) >> 1
		i, j = getpt(snm, 0, m)
		k, l = getpt(snm, i, m + j)
		l -= j
		'''
		for i, j in enumerate(snm):
			if m < j:
				break
		j = snm[i - 1]
		for k, l in enumerate(snm):
			if m < l - j:
				break
		l = snm[k - 1] - j
		#print 'm %d, sum %d, j %d, l %d, p %d' % (m, snm[n], j, l, snm[n] - j - l)
		'''
		if snm[n] - l - j <= m:
			t = m
		else:
			s = m + 1
	#print 'final: %d %d' % (s, t)
	res = (snm[n] - s) / float(snm[n])

	print "Case #%d: %.10f" % (case, res)
