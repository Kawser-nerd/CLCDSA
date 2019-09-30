def isset(a, bit): return ((a >> bit) & 1) > 0
def readint(): return int(raw_input())
def readfloat(): return float(raw_input())
def readarray(N, foo):
	res = []
	for i in xrange(N):
		res.append(foo())
	return res
def readlinearray(foo): return map(foo, raw_input().split())

def perms(xs):
	if len(xs) < 2:
		yield xs
		return
	h = []
	for x in xs:
		h.append(x)
		if x in h[:-1]: continue
		ts = xs[:]
		ts.remove(x)
		for ps in perms(ts):
			yield [x]+ps

for test in range(int(raw_input())):
	k = readint()
	s = raw_input()
	res = 10000000
	for p in perms(range(0, k)):
		s2 = ""
		for i in xrange(len(s)):
			g = i / k
			m = i % k
			s2 += s[g * k + p[m]]
		r = 0
		c = 0
		for i in xrange(len(s2)):
			if s2[i] != c:
				r += 1
				c = s2[i]
		res = min(r, res)
	print "Case #%d: %s" % (test + 1, res)
