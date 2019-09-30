def gcd(a, b):
	return a if b == 0 else gcd(b, a % b)

n = input()
for test in xrange(n):
	a, b = map(int, raw_input().split('/'))
	a, b = a / gcd(a, b), b / gcd(a, b)
	if (b & (b - 1)) == 0:
		res = 0
		while a < b:
			a *= 2
			res += 1
		print 'Case #%d: %d' % (test + 1, res)
	else:
		print 'Case #%d: impossible' % (test + 1)
