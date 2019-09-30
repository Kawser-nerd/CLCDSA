from collections import defaultdict
from math import log

def solve():
	n = int(raw_input())
	e = map(int, raw_input().split())
	f = map(int, raw_input().split())
	zeroes = int(log(f[0], 2))
	res = [0] * zeroes
	sums = defaultdict(int)
	for i in xrange(1, n):
		a = e[i]
		freq = f[i] / (2 ** zeroes)
		for j in xrange(freq - sums[a]):
			res.append(a)
			new_sums = defaultdict(int)
			new_sums[a] = 1
			for k, v in sums.iteritems():
				new_sums[k] += v
				new_sums[k + a] += v
			sums = new_sums
	return ' '.join(map(str, res))
	

for i in xrange(input()):
	print "Case #%d: %s" % (i + 1, solve())
