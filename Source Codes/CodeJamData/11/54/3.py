def run():
	s = raw_input()
	q = []
	a = 0
	for (i, b) in enumerate(reversed(s)):
		if (b == '?'): q.append(i)
		if (b == '1'): a += 1 << i
	if not q: return s
	for i in xrange(1 << len(q)):
		r = a
		for (j, b) in enumerate(q):
			if (((i >> j) & 1) == 0): continue
			r += 1 << b
		if r == int(r ** 0.5) ** 2:
			res = list(s)
			for (j, b) in enumerate(q):
				res[-b - 1] = '0' if ((i >> j) & 1) == 0 else '1'
			return ''.join(res)
	assert False
	
for test in xrange(input()):
	print "Case #%d: %s" % (test + 1, run())