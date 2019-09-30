import sys
def dbg(a): sys.stderr.write(str(a))
def readint(): return int(raw_input())
def readfloat(): return float(raw_input())
def readarray(foo): return map(foo, raw_input().split())

res = 0
used = {}
q = []
qh, qt = (0, 0)
dx1, dy1, dx2, dy2 = (0, 0, 0, 0)
w, h = (0, 0)

def doit(x, y):
	global res
	if x < 0 or x >= w: return
	if y < 0 or y >= h: return
	if (x, y) in used: return
	res += 1
	used[(x, y)] = True
	global q, qh, qt
	q.append((x + dx1, y + dy1))
	q.append((x + dx2, y + dy2))
	qt += 2

for test in range(readint()):
	dbg("Test %d\n" % (test + 1))
	(w, h) = readarray(int)
	(dx1, dy1) = readarray(int)
	(dx2, dy2) = readarray(int)
	(x0, y0) = readarray(int)
	res = 0
	used = {}
	q = [(x0, y0)]
	qh = 0
	qt = 1
	while qh < qt:
		(x, y) = q[qh]
		doit(x, y)
		qh += 1
	
	
	print "Case #%d: %d" % (test + 1, res)
