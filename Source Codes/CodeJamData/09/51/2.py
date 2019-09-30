import sys
import psyco
psyco.full()
def dbg(a): sys.stderr.write(str(a))

def readint(): return int(raw_input())
def readfloat(): return float(raw_input())
def readarray(N, foo): return [foo() for i in xrange(N)]
def readlinearray(foo): return map(foo, raw_input().split())
def encode(r, c): return (r << 4) + c
def decode(x): return ((x >> 4), x & 0xF)

def issafe(u):
	used = {}
	if (len(u) == 1): return True
	for i in u:
		(r, c) = decode(i)
		used[decode(i)] = True
	for i in u:
		(r, c) = decode(i)
		ok = False
		for (dr, dc) in ((-1, 0), (0, 1), (1, 0), (0, -1)):
			r2, c2 = r + dr, c + dc
			if (r2, c2) in used: ok = True
#			if (r2, c2) in used and (r, c2) not in used and (r2, c) not in used: return False
		if not ok: return False
	return True
		

def genmoves(u):
	safe = issafe(u)
	used = {}
	for i in u:	
		used[decode(i)] = True
	for i in xrange(len(u)):
		(r, c) = decode(u[i])
		for (dr, dc) in ((-1, 0), (0, 1), (1, 0), (0, -1)):
			r2, c2 = r + dr, c + dc
			r3, c3 = r - dr, c - dc
			if (r3, c3) not in free or (r3, c3) in used: continue
			if (r2, c2) in free and (r2, c2) not in used:
				lu = list(u)
				lu[i] = encode(r2, c2)
				v = tuple(sorted(lu))
				if (safe or issafe(v)):
					yield v
	return

def run_test(test):
	global R, C, free
	(R, C) = readlinearray(int)
	a = readarray(R, raw_input)
	free = {}
	mem = {}
	x0 = []
	y0 = []
	for r in xrange(R):
		for c in xrange(C):
			if (a[r][c] != '#'):
				free[(r, c)] = True
			if (a[r][c] == 'o' or a[r][c] == 'w'):
				x0.append(encode(r, c))
			if (a[r][c] == 'x' or a[r][c] == 'w'):
				y0.append(encode(r, c))
	x0 = tuple(x0)
	y0 = tuple(y0)
	mem[x0] = 0
	if (x0 == y0): return 0
	q = [x0]
	while True:
		q2 = []
		for u in q:
			d = mem[u]
			for v in genmoves(u):
				if v in mem:
					continue
				if v == y0: return d + 1
				mem[v] = d + 1
				q2.append(v)
		q = q2
		if (len(q) == 0): break
	
	return -1
	

for test in range(readint()):
	dbg("test %d\n" % test)
	res = run_test(test)
	print "Case #%d: %s" % (test + 1, str(res))
