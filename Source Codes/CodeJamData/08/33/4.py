#!/usr/bin/env python

def solve():
	signs, genlen, X, Y, Z = [ int(i) for i in raw_input().split() ]
	gen = []
	for _ in range(genlen):
		gen.append(int(raw_input()))

	r = { -1: 1 }
	for i in xrange(signs):
		limit = gen[i % genlen]
		gen[i % genlen] = (X * limit + Y * (i + 1)) % Z

		s = {}
		for j, n in r.iteritems():
			s[j] = s.get(j, 0) + n
			if limit > j:
				s[limit] = s.get(limit, 0) + n
		r = s

	return (sum(s.itervalues()) - 1) % 1000000007

for case in range(int(raw_input())):
	print 'Case #%d: %s' % (case + 1, solve())
