def readint(): return int(raw_input())
def readfloat(): return float(raw_input())
def readarray(N, foo):
	res = []
	for i in xrange(N):
		res.append(foo())
	return res
def readlinearray(foo): return map(foo, raw_input().split())


(L, D, N) = readlinearray(int)
words = readarray(D, raw_input)
patterns = readarray(N, raw_input)
for i in xrange(N):
	can = []
	pattern = patterns[i]
	pos = 0
	for p in xrange(L):
		d = {}
		c = pattern[pos]
		if (c != '('):
			d[c] = True
		else:
			while c != ')':
				pos += 1
				c = pattern[pos]
				d[c] = True
		pos += 1
		can.append(d)
	res = 0
	for j in xrange(D):
		ok = True
		for p in xrange(L):
			c = words[j][p]
			if (c in can[p]): continue
			ok = False
			break
		if ok: res += 1
	print "Case #%d: %s" % (i + 1, res)
