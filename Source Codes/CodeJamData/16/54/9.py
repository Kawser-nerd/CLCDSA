for case in xrange(1, input() + 1):
	N, L = map(int, raw_input().split())
	G = raw_input().split()
	B = raw_input()
	print "Case #" + str(case) + ":",
	if B in G:
		print "IMPOSSIBLE"
	else:
		if L > 1:
			print "0?" * L, "1" * (L - 1)
		else:
			print "? 0"