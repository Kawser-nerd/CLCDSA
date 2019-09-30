import sys
import psyco
psyco.full()
def dbg(a): sys.stderr.write(str(a))
def readint(): return int(raw_input())
def readfloat(): return float(raw_input())
def readarray(foo): return [foo(x) for x in raw_input().split()]


def run_test(test):
	R = readint()
	xy = [readarray(int) for i in xrange(R)]
	cur = {}
	for (x1, y1, x2, y2) in xy:
		for x in xrange(x1, x2 + 1):
			for y in xrange(y1, y2 + 1):
				cur[(x, y)] = True

	res = -1
	for T in xrange(10000):
		next = {}
		for (x, y) in cur:
			if (x - 1, y) in cur or (x, y - 1) in cur:
				next[(x, y)] = True
			if (x - 1, y + 1) in cur:
				next[(x, y + 1)] = True
		if len(next) == 0:
			res = T + 1
			break
		cur = next
	
	print "Case #%d: %d" % (test + 1, res)

for test in range(readint()):
	dbg("Test %d\n" % (test + 1))
	run_test(test)

