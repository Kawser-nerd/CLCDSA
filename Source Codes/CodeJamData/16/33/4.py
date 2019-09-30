for case in xrange(1, input() + 1):
	A, B, C, K = map(int, raw_input().split())
	print "Case #" + str(case) + ": " + str(A * B * min(K, C))
	ans = set()
	for i in xrange(min(K, C)):
		for j in xrange(1, A + 1):
			for k in xrange(1, B + 1):
				a, b, c = j, k, k + (i + j)
				while c > C:
					c -= C
				print a, b, c