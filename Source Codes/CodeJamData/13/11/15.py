def check(R, t, n):
	a1 = R * 2 - 1
	an = a1 + 4 * (n - 1)
	return (a1 + an) * n <= t * 2
		
def solve():
	R, t = map(int, raw_input().split())
	R += 1
	l = 1
	r = 10 ** 18
	while l + 1 < r:
		m = (l + r) / 2
		if check(R, t, m):
			l = m
		else:
			r = m
	return l

for i in xrange(input()):
	print "Case #%d: %d" % (i + 1, solve())
