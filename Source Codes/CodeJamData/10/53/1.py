import sys
import psyco
psyco.full()
def dbg(a): sys.stderr.write(str(a))
def readint(): return int(raw_input())
def readfloat(): return float(raw_input())
def readarray(foo): return [foo(x) for x in raw_input().split()]

def run_test(test):
	C = readint()
	a = dict([readarray(int) for i in xrange(C)])
	done = False
	res = 0
	while not done:
		done = True
		a2 = {}
		for k in a.keys():
			v = a[k]
			if v == 1:
				a2[k] = (a2[k] + 1) if (k in a2) else 1
				continue
			done = False
			a2[k - 1] = (a2[k - 1] + v / 2) if (k - 1 in a2) else v / 2
			a2[k + 1] = (a2[k + 1] + v / 2) if (k + 1 in a2) else v / 2
			res += v / 2
			if v % 2 == 1:
				a2[k] = (a2[k] + 1) if (k in a2) else 1
		a = a2
	return res

for test in range(readint()):
	dbg("Test %d\n" % (test + 1))
	print "Case #%d: %d" % (test + 1, run_test(test))
	
