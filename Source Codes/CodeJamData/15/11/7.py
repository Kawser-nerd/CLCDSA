T = int(raw_input())

for test in xrange(T):
	N = int(raw_input())
	m = map(int, raw_input().split())
	delta = []
	for i in xrange(len(m) - 1):
		delta.append(max(0, m[i] - m[i + 1]))
	y = 0
	z = 0
	minrate = max(delta)
	for i in xrange(len(m) - 1):
		y += delta[i]
		z += min(m[i], minrate)
	print "Case #{}: {} {}".format(test + 1, y, z)