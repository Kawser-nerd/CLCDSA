def ok(a, r0, c0, k):
	mr = r0 + k / 2.0
	mc = c0 + k / 2.0
	sr = 0
	sc = 0
	for r in xrange(r0, r0 + k):
		c1 = c0 if r0 < r < r0 + k - 1 else c0 + 1
		c2 = c0 + k if r0 < r < r0 + k - 1 else c0 + k - 1
		for c in xrange(c1, c2):
			sr += (r + 0.5 - mr) * a[r][c]
			sc += (c + 0.5 - mc) * a[r][c]
	return sr == 0 and sc == 0

def run():
	(R, C, D) = map(int, raw_input().split())
	a = [[D + int(d) for d in raw_input()] for i in xrange(R)]
	res = 2
	for r in xrange(R):
		for c in xrange(C):
			for k in xrange(res + 1, min(R - r, C - c) + 1):
				if ok(a, r, c, k):
					res = k
	return str(res) if res > 2 else "IMPOSSIBLE"

for t in xrange(input()):
	print "Case #%d: %s" % (t + 1, run())