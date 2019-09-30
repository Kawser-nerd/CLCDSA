import sys
def isset(n, i): return (n >> i) & 1 != 0
def dbg(a): sys.stderr.write(str(a))
def readint(): return int(raw_input())
def readfloat(): return float(raw_input())
def readarray(foo): return map(foo, raw_input().split())

for test in range(readint()):
	dbg("Test %d\n" % (test + 1))
	n = readint()
	data = []
	for i in xrange(n):
		(a, b, c) = readarray(int)
		data.append((a, b, c))
	res = 0
	for A in xrange(10001):
		q = []
		for (a, b, c) in data:
			if (a > A): continue
			if (A + b > 10000): continue
			minb = b
			maxb = 10000 - A - c
			if (maxb < minb): continue
			q.append((minb, 0))
			q.append((maxb, 1))
		q.sort()
		r = 0
		for (t, d) in q:
			if d == 0:
				r += 1
				res = max(res, r)
			else:
				r -= 1
	print "Case #%d: %d" % (test + 1, res)
