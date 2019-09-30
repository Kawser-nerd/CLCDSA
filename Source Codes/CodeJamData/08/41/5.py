def readint(): return int(raw_input())
def readfloat(): return float(raw_input())
def readarray(N, foo):
	res = []
	for i in xrange(N):
		res.append(foo())
	return res
def readlinearray(foo): return map(foo, raw_input().split())


def doit(p, v):
	if (p, v) in mem: return mem[(p, v)]
	if not node[p]:
		return 0 if v == val[p] else 1000000
	resand = 1000000
	resor = 1000000
	res = 1000000
	if v == 0:
		resand = min(doit(2 * p + 1, 0), doit(2 * p + 2, 0))
		resor = doit(2 * p + 1, 0) + doit(2 * p + 2, 0)
	else:
		resand = doit(2 * p + 1, 1) + doit(2 * p + 2, 1)
		resor = min(doit(2 * p + 1, 1), doit(2 * p + 2, 1))
	if val[p] == 1: #and
		res = resand
		if (change[p] and res > 1 + resor):
			res = 1 + resor
	else:
		res = resor
		if (change[p] and res > 1 + resand):
			res = 1 + resand
	mem[(p, v)] = res
	return res
		

for test in range(int(raw_input())):
	(m, v) = readlinearray(int)
	node = []
	change = []
	val = []
	for i in xrange(m):
		if i < (m - 1) / 2:
			(g, c) = readlinearray(int)
			node.append(True)
			val.append(g)
			change.append(c == 1)
		else:
			g = readint()
			node.append(False)
			val.append(g)
			change.append(False)
	mem = {}
	res = doit(0, v)
	if res >= 1000000: res = "IMPOSSIBLE"
	print "Case #%d: %s" % (test + 1, res)
