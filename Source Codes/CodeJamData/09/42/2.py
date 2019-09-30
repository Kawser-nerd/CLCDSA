import sys
import psyco
psyco.full()
def dbg(a): sys.stderr.write(str(a))

def readint(): return int(raw_input())
def readarray(N, foo): return [foo() for i in xrange(N)]
def readlinearray(foo): return map(foo, raw_input().split())


res = 10000

def doit(r, c, n):
	global res
	if (r == R - 1):
		res = min(res, n)
		return
	for i in xrange(c, -1, -1):
		if (i == 0 or (a[r][i - 1]) or (not a[r + 1][i - 1])): break
	s = i
	for i in xrange(c, C + 1):
		if (i == C - 1 or a[r][i + 1] or (not a[r + 1][i + 1])): break
	e = i
#	dbg("%d %d\n" % (r, c))

	if (s > 0 and not a[r][s - 1]):
		c2 = s - 1
		assert not a[r + 1][c2]
		for i in xrange(r + 1, R):
			if (i == R - 1 or a[i + 1][c2]): break
		r2 = i
		if (r2 - r <= F):
			doit(r2, c2, n)
	if (e < C - 1 and not a[r][e + 1]):
		c2 = e + 1
		assert not a[r + 1][c2]
		for i in xrange(r + 1, R):
			if (i == R - 1 or a[i + 1][c2]): break
		r2 = i
		if (r2 - r <= F):
			doit(r2, c2, n)
	
	if (e - s > 0):
		for c2 in xrange(s + 1, e + 1):
			assert a[r + 1][c2 - 1]
			a[r + 1][c2 - 1] = False
			doit(r, c2, n + 1)
			a[r + 1][c2 - 1] = True
		for c2 in xrange(s, e):
			assert a[r + 1][c2 + 1]
			a[r + 1][c2 + 1] = False
			doit(r, c2, n + 1)
			a[r + 1][c2 + 1] = True
		
	


def run_test(test):
	global R, C, F, a
	(R, C, F) = readlinearray(int)
	sa = readarray(R, raw_input)
	a = []
	for i in xrange(R):
		a.append([])
		for j in xrange(C):
			a[i].append(sa[i][j] == '#')
	doit(0, 0, 0)
	if (res == 10000):
		print "Case #%d: No" % (test + 1)
	else:
		print "Case #%d: Yes %s" % (test + 1, str(res))

for test in range(readint()):
	res = 10000
	dbg("test %d\n" % test)
	run_test(test)
