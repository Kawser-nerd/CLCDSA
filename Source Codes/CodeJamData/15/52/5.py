def solve():
	n, k = map(int, raw_input().split())
	s = map(int, raw_input().split())
	sizes = []
	summin = 0
	for i in xrange(k):
		a = 0 if i != k - 1 else s[0]
		seq = [a]
		for j in xrange(i, n - k, k):
			a += s[j + 1] - s[j]
			seq.append(a)
		m = min(seq)
		sizes.append(max(seq) - m)
		summin += m
	sizes.sort()
	left = summin % k
	res = sizes[-1]
	for i in xrange(k):
		left -= res - sizes[i]
	if left > 0: res += 1
	return res
	

for i in xrange(input()):
	print "Case #%d: %d" % (i + 1, solve())
