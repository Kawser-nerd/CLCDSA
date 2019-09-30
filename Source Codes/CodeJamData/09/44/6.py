import sys
import psyco
psyco.full()
def dbg(a): sys.stderr.write(str(a))

def readint(): return int(raw_input())
def readarray(N, foo): return [foo() for i in xrange(N)]
def readlinearray(foo): return map(foo, raw_input().split())

def rdist(a, b):
	dx = a[0] - b[0]
	dy = a[1] - b[1]
	d = pow(dx * dx + dy * dy, .5)
	return (d + a[2] + b[2]) / 2.0

def run_test(test):
	n = readint()
	a = readarray(n, lambda: readlinearray(int))
	if n == 1:
		res = a[0][2]
	elif n == 2:
		res = max(a[0][2], a[1][2])
	else:
		res = min([
			max(a[0][2], rdist(a[1], a[2])),
			max(a[1][2], rdist(a[0], a[2])),
			max(a[2][2], rdist(a[0], a[1])),
		])
	print "Case #%d: %.6f" % (test + 1, res)

for test in range(readint()):
	dbg("test %d\n" % test)
	run_test(test)
