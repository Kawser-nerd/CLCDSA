T = int(raw_input())
for i in range(1, T + 1):
	print "Case #%d:" % i,
	b, m = [int(x) for x in raw_input().split()]
	if (1 << (b - 2)) < m:
		print "IMPOSSIBLE"
	else:
		print "POSSIBLE"
		bb = b
		while bb >= 3 and (1 << (bb - 3)) >= m:
			bb -= 1
		ans = [[0] * b for i in range(b)]
		if bb != b:
			ans[bb - 1][b - 1] = 1
		for i in range(bb):
			for j in range(i):
				ans[j][i] = 1
		mm = (1 << (bb - 2)) - m
		for i in range(0, bb):
			if mm >> i & 1:
				ans[i + 1][bb - 1] = 0
		print '\n'.join([''.join([str(y) for y in x]) for x in ans])