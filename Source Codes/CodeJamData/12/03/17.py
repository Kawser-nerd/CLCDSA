
from collections import defaultdict as dd


tri = lambda n: (n*(n+1))/2

sigs = {}

for n in xrange(1, 2000000+1):
	s = str(n)
	rots = [s[b:]+s[:b] for b in xrange(len(s))]
	rots.sort()
	sigs[n] = rots[0]


T = int(raw_input())

for t in xrange(1, T+1):
	A, B = map(int, raw_input().split())
	sigc = dd(int)
	for n in xrange(A, B+1):
		sigc[sigs[n]] += 1
	count = sum(tri(v-1) for v in sigc.values())
	print 'Case #%s: %s'%(t, count)


