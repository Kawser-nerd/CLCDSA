def run():
	(x, s, r, t, n) = map(int, raw_input().split())
	r -= s
	pos = 0
	speeds = []
	for i in xrange(n):
		(b, e, w) = map(int, raw_input().split())
		speeds.append((pos, b, s))
		speeds.append((b, e, s + w))
		pos = e
	speeds.append((pos, x, s))

	res = 0
	speeds.sort(key = lambda x: x[2])
	for (b, e, w) in speeds:
		l = e - b
		if l == 0: continue
		t1 = min(t, 1.0 * l / (w + r))
		t2 = 1.0 * (l - t1 * (w + r)) / w
		res += t1 + t2
		t -= t1
	
	return res

for t in xrange(input()):
	print "Case #%d: %.6f" % (t + 1, run())