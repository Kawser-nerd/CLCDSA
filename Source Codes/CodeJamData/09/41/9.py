import sys
import psyco
psyco.full()
def dbg(a): sys.stderr.write(str(a))

def readint(): return int(raw_input())
def readfloat(): return float(raw_input())
def readarray(N, foo): return [foo() for i in xrange(N)]
def readlinearray(foo): return map(foo, raw_input().split())
def dig(c):
	c = ord(c)
	if c >= 97:
		return c - 87
	return c - 48

def run_test(test):
	n = readint()
	a = readarray(n, raw_input)
	maxpos = [0] * n
	used = [False] * n
	for i in xrange(n):
		for j in xrange(n):
			if (a[i][j] == "1"):
				maxpos[i] = j
	res = 0
	for i in xrange(n):
		for j in xrange(i, n):
			if (maxpos[j] > i): continue
			for k in xrange(j, i, -1):
				(maxpos[k], maxpos[k - 1]) = (maxpos[k - 1], maxpos[k])
				res += 1
			break
	print "Case #%d: %s" % (test + 1, str(res))

for test in range(readint()):
	dbg("test %d\n" % test)
	run_test(test)
