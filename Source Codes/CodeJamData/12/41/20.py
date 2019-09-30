for test in range(input()):
	n = input()
	d = [0]*n
	l = [0]*n
	for i in xrange(n):
		d[i],l[i] = map(int,raw_input().split())
	D = input()
	m = [0]*n
	mp = 1
	m[0] = d[0]*2
	for i in xrange(n):
		while mp<n and d[mp]<=m[i]:
			m[mp] = d[mp]+min(l[mp],d[mp]-d[i])
			mp += 1
	"""
	print d
	print l
	print D
	print m
	"""
	print "Case #%s: %s"%(test+1,"YES" if max(m)>=D else "NO")
