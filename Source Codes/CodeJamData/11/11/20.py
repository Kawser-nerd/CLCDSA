def run():
	N, Pd, Pg = map(int, raw_input().split())
	if Pg == 0 and Pd > 0:
		return "Broken"
	if Pg == 100 and Pd < 100:
		return "Broken"
	for i in xrange(1, min(N, 100) + 1):
		if (Pd * i) % 100 == 0: return "Possible"
	return "Broken"

for i in xrange(input()):
	print "Case #%d: %s" % (i + 1, run())