def find(a, x):
	if x == 0: return a[0][1]
	last = (0, a[0][1])
	for (nx, ny) in a[1:]:
		if nx < x:
			last = (nx, ny)
			continue
		lx, ly = last
		p = (x - lx) * 1.0 / (nx - lx)
		return ly + (ny - ly) * p
	return None

def findx(x0, y1, y2, area):
	l = 0.0
	r = x0
	for i in xrange(100):
		m = (l + r) / 2.0
		if m * (y1 + y1 + (y2 - y1) * m / x0) / 2.0 > area:
			r = m
		else:
			l = m
	return l

def run():
	(W, L, U, G) = map(int, raw_input().split())
	low = [map(int, raw_input().split()) for i in xrange(L)]
	high = [map(int, raw_input().split()) for i in xrange(U)]
	xs = sorted(set([x[0] for x in low] + [x[0] for x in high]))
	a = [(x, find(high, x) - find(low, x)) for x in xs]
	area = 0.0
	lx, ly = a[0]
	for (x, y) in a[1:]:
		area += (x - lx) * ((y + ly) / 2.0)
		lx, ly = x, y
	nextarea = area / G
	curarea = 0.0
	lx, ly = a[0]
	res = []
	for (x, y) in a[1:]:
		na = (x - lx) * ((y + ly) / 2.0)
		while curarea + na > nextarea:
			res.append(lx + findx(x - lx, ly, y, nextarea - curarea))
			nextarea += area / G
		lx, ly = x, y
		curarea += na
	return res[:G - 1]
	

for test in xrange(input()):
	print "Case #%d:\n%s" % (test + 1, "\n".join(map(str, run())))