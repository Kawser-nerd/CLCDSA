def score(w, l, words):
	used = set()
	res = 0
	for c in l:
		for u in words:
			if u == w: continue
			if len(u) != len(w): continue
			if c not in u: continue
			for j in xrange(len(w)):
				if u[j] == w[j]: continue
				if u[j] in used or w[j] in used: break
			else:
				if c not in w: res += 1
				break
		used.add(c)
	return res

def run():
	(n, m) = map(int, raw_input().split())
	words = [raw_input() for i in xrange(n)]
	lists = [raw_input() for i in xrange(m)]
	res = []
	for l in lists:
		best, bestw = (-1, None)
		for w in words:
			r = score(w, l, words)
			if r > best:
				best, bestw = r, w
		res.append(bestw)
	return " ".join(res)
			

for i in xrange(input()):
	print "Case #%d: %s" % (i + 1, run())