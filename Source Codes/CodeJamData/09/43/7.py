import sys
import psyco
psyco.full()
def dbg(a): sys.stderr.write(str(a))

def isset(a, bit): return ((a >> bit) & 1) > 0
def readint(): return int(raw_input())
def readarray(N, foo): return [foo() for i in xrange(N)]
def readlinearray(foo): return map(foo, raw_input().split())


def doit(m):
	if (m == 0): return 0
	if m in mem: return mem[m]
	res = 1000
	bits = [i for i in xrange(n) if isset(m, i)]
	bit = bits[0]
	for m2 in masks[bit]:
		if (m2 | m) != m: continue
		r = 1 + doit(m ^ m2)
		res = min(res, r)
	mem[m] = res
	return res

def run_test(test):
	global n
	(n, k) = readlinearray(int)
	a = readarray(n, lambda: readlinearray(int))
	good = {}
	for i in xrange(n):
		for j in xrange(i + 1, n):
			ok = True
			more = False
			less = False
			for t in xrange(k):
				if (a[i][t] == a[j][t]):
					ok = False
					break
				if (a[i][t] > a[j][t]):
					more = True
				else:
					less = True
			if (ok and not (more and less)):
				good[(i, j)] = True

	goodm = {}
	for m in xrange(1, 1 << n):
		ok = True
		for i in xrange(n):
			if not isset(m, i): continue
			for j in xrange(i + 1, n):
				if not isset(m, j): continue
				if (i, j) not in good:
					ok = False
					break
			if not ok: break
		if ok: goodm[m] = True
	global masks
	global mem
	masks = [[] for i in xrange(n)]
	mem = {}
	for m in goodm:
		for i in xrange(n):
			if not isset(m, i): continue
			masks[i].append(m)
			break
	res = doit((1 << n) - 1)
	print "Case #%d: %s" % (test + 1, str(res))

for test in range(readint()):
	dbg("test %d\n" % test)
	run_test(test)
