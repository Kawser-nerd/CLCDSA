for case in xrange(1, input() + 1):
	B, M = map(int, raw_input().split())
	if M > 2 ** (B - 2):
		print "Case #" + str(case) + ": IMPOSSIBLE"
	else:
		print "Case #" + str(case) + ": POSSIBLE"
		edges = [(1, B)]
		M -= 1
		for i, x in enumerate(bin(M)[2:].zfill(B - 2)):
			if x == '1':
				edges.append((1, i + 2))
		ans = [[0 for i in xrange(B + 1)] for j in xrange(B + 1)]
		for i in xrange(2, B + 1):
			for j in xrange(i + 1, B + 1):
				ans[i][j] = 1
		for x, y in edges:
			ans[x][y] = 1
		for x in ans[1:]:
			print ''.join(map(str, x[1:]))