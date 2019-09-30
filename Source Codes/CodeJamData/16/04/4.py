T = input()
for t in xrange(T):
	K, C, S = map(int, raw_input().split())
	print "Case #" + str(t+1) + ":",
	if S * C < K:
		print "IMPOSSIBLE"
	else:
		u = set()
		la = 0
		while la < K:
			s = 0
			for i in xrange(C):
				s *= K
				s += min(K-1, la)
				la += 1
			u.add(s+1)
		print " ".join(map(str,list(u)))