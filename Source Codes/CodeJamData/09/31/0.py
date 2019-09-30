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
	s = raw_input()
	if (len(s) == 1):
		print "Case #%d: %s" % (test + 1, str(1))
		return
		
	b = 2
	m = {}
	m[s[0]] = 1
	zero = False
	for c in s[1:]:
		if (c in m): continue
		if not zero:
			m[c] = 0
			zero = True
			continue
		m[c] = b
		b += 1
	res = 0
	for c in s:
		res *= b
		res += m[c]

	print "Case #%d: %s" % (test + 1, str(res))

for test in range(readint()):
	dbg("test %d\n" % test)
	run_test(test)
