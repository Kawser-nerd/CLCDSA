import sys
import psyco
psyco.full()
def dbg(a): sys.stderr.write(str(a))
def readint(): return int(raw_input())
def readfloat(): return float(raw_input())
def readarray(foo): return [foo(x) for x in raw_input().split()]

def doit(p, last):
	if (p, last) in mem: return mem[(p, last)]
	if (p == N): return 0
	res = doit(p + 1, last) + D
	for i in xrange(256):
		if last == -1:
			res = min(res, doit(p + 1, i) + abs(a[p] - i))
			continue
		diff = abs(last - i)
		if M == 0 and diff > 0: continue
		insertcost = ((diff - 1) / M) * I if (diff > 0 and I > 0) else 0
		editcost = abs(a[p] - i)
		res = min(res, doit(p + 1, i) + editcost + insertcost)
	mem[(p, last)] = res
	return res

def run_test(test):
	global D, I, M, N, a, mem
	(D, I, M, N) = readarray(int)
	a = readarray(int)
	mem = {}
	res = doit(0, -1)
	print "Case #%d: %d" % (test + 1, res)

for test in range(readint()):
	dbg("Test %d\n" % (test + 1))
	run_test(test)

