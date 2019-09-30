import sys
from copy import deepcopy
def isset(n, i): return (n >> i) & 1 != 0
def dbg(a): sys.stderr.write(str(a))
def readint(): return int(raw_input())
def readfloat(): return float(raw_input())
def readarray(foo): return map(foo, raw_input().split())


def valid(m, u):
	for r in xrange(len(m)):
		for c in xrange(len(m[0])):
			s = sum(u, r, c)
			if m[r][c] != s: return False
	return True

def sum(u, r, c):
	res = 0
	h = len(u)
	w = len(u[0])
	for dr in [-1,0,1]:
		for dc in [-1,0,1]:
			r2 = r + dr
			c2 = c + dc		
			if (r2 < 0 or r2 >= h or c2 < 0 or c2 >= w): continue
			res += u[r2][c2]
	return res
			

def find(u, u2, m2):
	used2 = [[0] * w, u, u2]
	for i in xrange(1 << w):
		for j in xrange(w):
			used2[0][j] = 1 if isset(i, j) else 0
#		dbg(str(used2) + "\n")
		if valid(m2, used2): return used2[0]
	return [0] * w
			

for test in range(readint()):
	dbg("Test %d\n" % (test + 1))
	(h, w) = readarray(int)
	m = []
	for i in xrange(h):
		m.append(readarray(int))
	best = 0
	r0 = 0 if h == 3 else 1
	for i in xrange(1 << (3 * w)):
		used = []
		for r in xrange(h):
			used.append([0] * w)
		res = 0
		for dr in xrange(3):
			for dc in xrange(w):
				j = dr * w + dc
				if not isset(i, j): continue
				used[r0 + dr][dc] = 1
				if dr == 1: res += 1
#		dbg(str(i) + " " + str(used))
#		dbg("\n")
		if h == 5:
			used[0] = find(used[1], used[2], [m[0], m[1]])
			used[4] = find(used[3], used[2], [m[4], m[3]])
		if not valid(m, used): continue
		best = max(best, res)
		
	print "Case #%d: %d" % (test + 1, best)
