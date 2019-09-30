import sys, copy
sys.setrecursionlimit(10000)
data = [line.split() for line in sys.stdin.readlines()]
tn = int(data[0][0])
ln = 1
for ti in xrange(tn):
	m = int(data[ln][0])
	n = int(data[ln][1])
	s = []
	for i in xrange(m):
		s.append(data[ln+1+i][0])
	ln += m+1
	def solve(t, k):
		r1 = 0
		r2 = 0
		if k == m:
			for i in xrange(n):
				r1 += len(t[i])
			return (r1, 1)
		for i in xrange(n):
			tiorig = copy.deepcopy(t[i])
			for j in xrange(len(s[k])+1):
				t[i].add(s[k][:j])
			r1a, r2a = solve(t, k+1)
			t[i] = tiorig
			if r1a > r1:
				r2 = 0
		   	if r1a >= r1:
		   		r1 = r1a
		   		r2 = (r2 + r2a) % 1000000007
		return (r1, r2)
	r1, r2 = solve([set() for i in xrange(n)], 0)
	print "Case #%d: %d %d" % (ti+1, r1, r2)
	sys.stdout.flush()
