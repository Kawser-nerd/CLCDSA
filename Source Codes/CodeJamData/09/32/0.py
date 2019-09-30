import sys
import psyco
psyco.full()
def dbg(a): sys.stderr.write(str(a))

def alloc(size, default = 0): return [default] * size
def alloc2(r, c, default = 0): return [alloc(c, default)] * r
def isset(a, bit): return ((a >> bit) & 1) > 0
def readint(): return int(raw_input())
def readfloat(): return float(raw_input())
def readarray(N, foo): return [foo() for i in xrange(N)]
def readlinearray(foo): return map(foo, raw_input().split())
def dig(c): return ord(c) - 48

def dist(c, t):
	x = c[0] + t * c[3]
	y = c[1] + t * c[4]
	z = c[2] + t * c[5]
	return x * x + y * y + z * z

def run_test(test):
	N = readint()
	sum = alloc(6)
	for i in xrange(N):
		c = readlinearray(int)
		for d in xrange(6):
			sum[d] += c[d]
	ave = [float(d) / N for d in sum]
	l = 0.0
	r = 1e15
	if (sum[3] == 0 and sum[4] == 0 and sum[5] == 0): r = 0
	for i in xrange(1000):
		m1 = (l + l + r) / 3
		m2 = (l + r + r) / 3
		d1 = dist(ave, m1)
		d2 = dist(ave, m2)
		if d1 < d2:
			r = m2
		else:
			l = m1
	
	res = 0

	print "Case #%d: %.6f %.6f" % (test + 1, pow(dist(ave, l), .5), l)

for test in range(readint()):
	dbg("test %d\n" % test)
	run_test(test)
