from sys import stdout
from itertools import combinations

def solve(s):
	a = {}
	for x in xrange(1, len(s) + 1):
		for c in combinations(s, x):
			t = sum(c)
			if t not in a:
				a[t] = c
			else:
				print ' '.join(str(x) for x in a[t])
				print ' '.join(str(x) for x in c)
				return
	print "Impossible"

for case in xrange(1, int(raw_input()) + 1):
	s = [int(d) for d in raw_input().split()[1:]]
	stdout.write("Case #%d:\n" % case)
	solve(s)
