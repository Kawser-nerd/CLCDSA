import sys
import psyco
psyco.full()
def dbg(a): sys.stderr.write(str(a))
def readint(): return int(raw_input())
def readarray(foo): return [foo(x) for x in raw_input().split()]


def doit(match, missed):
	if match >= len(a):
		return -1 if missed > M[match - len(a)] else 0
	if (match, missed) in mem: return mem[(match, missed)]
	m1 = match * 2 + 1
	m2 = match * 2 + 2

	r1 = doit(m1, missed)
	r2 = doit(m2, missed)
	if r1 == -1 or r2 == -1:
		mem[(match, missed)] = -1
		return -1
		
	res = r1 + r2 + a[match]
	q1 = doit(m1, missed + 1)
	q2 = doit(m2, missed + 1)
	if q1 >= 0 and q2 >= 0:
		res = min(res, q1 + q2)
	mem[(match, missed)] = res
	return res


def run_test(test):
	global P, M, a, mem
	P = readint()
	M = readarray(int)
	data = []
	a = []
	for i in xrange(P):
		data.append(readarray(int))
	for arr in reversed(data):
		a += arr
	mem = {}
	res = doit(0, 0)
	print "Case #%d: %d" % (test + 1, res)

for test in range(readint()):
	dbg("Test %d\n" % (test + 1))
	run_test(test)

