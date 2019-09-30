def isset(a, bit): return ((a >> bit) & 1) > 0
def readint(): return int(raw_input())
def readfloat(): return float(raw_input())
def readarray(N, foo):
	res = []
	for i in xrange(N):
		res.append(foo())
	return res
def readlinearray(foo): return map(foo, raw_input().split())

def doit(k, prev):
	if k == c: return 0
	if (k, prev) in mem: return mem[(k, prev)]
	res = 0
	for m in xrange(1 << r):
		b = 0
		ok = True
		for i in xrange(r):
			if not isset(m, i): continue
			b += 1
			if not good[i][k] or isset(prev, i) or isset(prev, i + 1) or (i > 0 and isset(prev, i - 1)):
				ok = False
				break
		if not ok: continue
		res = max(res, b + doit(k + 1, m))
	mem[(k, prev)] = res
	return res
			

for test in range(int(raw_input())):
	(r, c) = readlinearray(int)
	good = []
	for i in xrange(r):
		s = raw_input()
		t = []
		for j in xrange(c):
			t.append(s[j] == '.')
		good.append(t)
	mem = {}
	res = doit(0, 0)
	print "Case #%d: %s" % (test + 1, res)
