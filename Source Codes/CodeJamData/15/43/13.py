def solve():
	n = int(raw_input())
	text = [raw_input().split() for _ in xrange(n)]
	base = [set(text[0]), set(text[1])]
	base_res = len(base[0] & base[1])
	if n == 2: return base_res
	res = 1e9
	for i in xrange(2 ** (n - 2)):
		added = [set(), set()]
		for j in xrange(n - 2):
			lang = ((i >> j) & 1)
			for word in text[j + 2]:
				if not word in base[lang]:
					added[lang].add(word)
		r = len(added[0] & base[1]) + len(added[1] & base[0]) + len(added[0] & added[1])
		res = min(res, base_res + r)
	return res
				
	

for i in xrange(input()):
	print "Case #%d: %s" % (i + 1, solve())
