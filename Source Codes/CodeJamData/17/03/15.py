for tc in range(input()):
	N, K = map(int, raw_input().split())
	s = 1
	x = N
	lc = 1
	sc = 0
	while K > s:
		if x % 2 == 0:
			lc, sc = lc, lc + 2 * sc
		else:
			lc, sc = 2 * lc + sc, sc
		x = x / 2
		K = K - s
		s = s * 2
	x = x if K <= lc else x - 1
	if x % 2 == 0:
		print "Case #%d: %d %d" % (tc + 1, x / 2, x / 2 - 1)
	else:
		print "Case #%d: %d %d" % (tc + 1, x / 2, x / 2)
		
