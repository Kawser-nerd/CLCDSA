for case in xrange(1, input() + 1):
	S = raw_input()
	ans = 0
	c = 1
	while c:
		c = 0
		X = ""
		for x in S:
			if not X:
				X += x
			else:
				if x == X[-1]:
					X = X[:-1]
					ans += 10
					c = 1
				else:
					X += x
		S = X
	print "Case #" + str(case) + ":",
	print ans + len(X)/2 * 5