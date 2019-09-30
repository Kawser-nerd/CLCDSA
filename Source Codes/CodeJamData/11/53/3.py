def check(a, n, m, i):
	used = set()
	for r in xrange(n):
		for c in xrange(m):
			d = a[r][c]
			if ((i >> (r * m + c)) & 1 == 1):
				d = (-d[0], -d[1])
			nr, nc = (r + d[0]) % n, (c + d[1]) % m
			if (nr, nc) in used: return False
			used.add((nr, nc))
	return True

def run():
	(n, m) = map(int, raw_input().split())
	a = []
	dirs = {
		'|' : (1, 0),
		'-' : (0, 1),
		'/' : (1, -1),
		'\\' : (1, 1),
	}
	for i in xrange(n):
		a.append([])
		s = raw_input()
		for j in xrange(m):
			a[i].append(dirs[s[j]])
	res = 0
	for i in xrange(1 << (n * m)):
		if check(a, n, m, i): res += 1
	return res
	
for test in xrange(input()):
	print "Case #%d: %d" % (test + 1, run())