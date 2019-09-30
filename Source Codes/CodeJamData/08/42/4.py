def readlinearray(foo): return map(foo, raw_input().split())

def doit(n, m, a):
	for x1 in xrange(n + 1):
		for y1 in xrange(m + 1):
			for x2 in xrange(n + 1):
				q = a + x2 * y1
				if x1 == 0:
					if q != 0: continue
					y2 = 0
				else:
					if q % x1 != 0: continue
					y2 = q / x1
				if (y2 > m or y2 < 0): continue
				return "%d %d %d %d %d %d" % (0, 0, x1, y1, x2, y2)
	return "IMPOSSIBLE"

for test in range(int(raw_input())):
	(n, m, a) = readlinearray(int)		
	res = doit(n, m, a)
	print "Case #%d: %s" % (test + 1, res)

