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


def doit(n, m):
	if m <= n: return 0
	if (n, m) in mem: return mem[(n, m)]
	res = None
	for i in xrange(n, m + 1):
		if i not in free: continue
		r = m - n + doit(n, i - 1) + doit(i + 1, m)
		if res is None or res > r:
			res = r
	if res is None: res = 0
	mem[(n, m)] = res
	return res

def run_test(test):
	global free, mem
	(N, Q) = readlinearray(int)
	qs = readlinearray(int)
	free = {}
	for q in qs: free[q] = True
	mem = {}
	res = doit(1, N)
	print "Case #%d: %s" % (test + 1, str(res))

for test in range(readint()):
	dbg("test %d\n" % test)
	run_test(test)
