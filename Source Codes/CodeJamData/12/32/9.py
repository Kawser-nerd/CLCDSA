import sys, math, os, re
_tokiter = iter(sys.stdin.read().split()); get = lambda: next(_tokiter)
scanf = lambda *types: [t(get()) for t in types]

def testcase(id):
	d, n, a = scanf(float, int, int)
	ocar = [scanf(float, float) for i in xrange(n)]
	accel = [scanf(float)[0] for i in xrange(a)]
	print 'Case #%d:' % id
	if len(ocar) == 1:
		mintime = 0
	else:
		oslope = (ocar[1][1] - ocar[0][1]) / (ocar[1][0] - ocar[0][0])
		ob = ocar[0][1] - ocar[0][0] * oslope
		mintime = (d - ob) / oslope
	for ac in accel:
		ans = max(mintime, math.sqrt(2*d/ac))
		print '%.6f' % ans


ncases, = scanf(int)
for i in xrange(ncases):
	print >>sys.stderr, 'Running case #%d' % (i+1)
	testcase(i+1)
