import sys
def dbg(a): sys.stderr.write(str(a))
def readint(): return int(raw_input())
def readfloat(): return float(raw_input())
def readarray(foo): return map(foo, raw_input().split())


def doit(u, p):
	c = k
	s = len(to[u])
	if (p >= 0):
		c -= len(to[p])
		s -= 1
	cnks.append((c, s))
	for v in to[u]:
		if v == p: continue
		doit(v, u)

M = 1000000009
def cnk(n, k):
	res = 1
	for i in xrange(k):
		res *= n - i
		res %= M
	return res


for test in range(readint()):
	dbg("Test %d\n" % (test + 1))
	n, k = readarray(int)
	to = []
	cnks = []
	for i in xrange(n):
		to.append([])
	for i in xrange(n - 1):
		(u, v) = readarray(int)
		to[u - 1].append(v - 1)
		to[v - 1].append(u - 1)
	doit(0, -1)
	
	res = 1
	for (c, s) in cnks:
		if (s > c): res = 0
		res *= cnk(c, s)
		res %= M
#	dbg(cnks)	
	print "Case #%d: %d" % (test + 1, res)
