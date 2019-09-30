import sys

lc = 0
for line in sys.stdin:
	tok = line.split()
	if len(tok) == 1: continue

	lc += 1

	r, t = map(int, tok)
	lo = 0
	hi = t
	while hi - lo > 1:
		m = (lo + hi) / 2;
		if 2 * m * r + (1 + 4 * m - 3) / 2 * m <= t: lo = m
		else: hi = m
	
	print "Case #{0}: {1}".format(lc, lo)