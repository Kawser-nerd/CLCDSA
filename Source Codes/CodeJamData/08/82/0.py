import sys
def dbg(a): sys.stderr.write(str(a))
def readint(): return int(raw_input())
def readfloat(): return float(raw_input())
def readarray(foo): return map(foo, raw_input().split())

M = 1 << 30

def solve(s):
	pos = 1
	s.sort()
	r = 0
	while pos <= 10000:
		best = -1
		for (a, b) in s:
			if a > pos: break
			if b > best:
				best = b
		if (best < pos):
			return M
		pos = best + 1
		r += 1
	return r
		
for test in range(readint()):
	dbg("Test %d\n" % (test + 1))
	cids = {}
	colors = 0
	segs = []
	n = readint()
	for i in xrange(n):
		(cs, a, b) = readarray(str)
		if cs not in cids:
			cids[cs] = colors
			colors += 1
			segs.append([])
		c = cids[cs]
		segs[c].append((int(a), int(b)))
	res = M
	for c1 in xrange(colors):
		s1 = segs[c1]
		res = min(res, solve(s1))
		for c2 in xrange(c1 + 1, colors):
			s2 = s1 + segs[c2]
			res = min(res, solve(s2))
			for c3 in xrange(c2 + 1, colors):
				s3 = s2 + segs[c3]
				res = min(res, solve(s3))
#	dbg(segs)
	ans = res if res != M else "IMPOSSIBLE"
	print "Case #%d: %s" % (test + 1, ans)
