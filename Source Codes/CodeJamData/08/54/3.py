def readint(): return int(raw_input())
def readfloat(): return float(raw_input())
def readarray(N, foo):
	res = []
	for i in xrange(N):
		res.append(foo())
	return res
def readlinearray(foo): return map(foo, raw_input().split())

M = 10007

def doit(r, c):
	if r == h and c == w: return 1
	if (r, c) in mem: return mem[(r, c)]
	if (r, c) in used: return 0
	res = 0
	if (r + 2 <= h and c + 1 <= w):
		res += doit(r + 2, c + 1)
	if (r + 1 <= h and c + 2 <= w):
		res += doit(r + 1, c + 2)
	res %= M
	mem[(r, c)] = res
	return res

for test in range(int(raw_input())):
	(h, w, R) = readlinearray(int)
#	r = []
#	c = []
	used = {}
	for i in xrange(R):
		(r, c) = readlinearray(int)
		used[(r, c)] = True
#		r.append(y)
#		c.append(x)
	mem = {}
	res = doit(1, 1)
	print "Case #%d: %s" % (test + 1, res)
