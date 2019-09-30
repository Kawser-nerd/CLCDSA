import sys
import psyco
psyco.full()
def isset(a, b): return ((a >> b) & 1) != 0
def dbg(a): sys.stderr.write(str(a))
def readint(): return int(raw_input())
def readfloat(): return float(raw_input())
def readarray(foo): return [foo(x) for x in raw_input().split()]

def run_test(test):
	global n, m, a
	dbg("Test %d\n" % (test + 1))
	n, m = readarray(int)
	a = []
	for i in xrange(n):
		a.append(readarray(int))
	
	dr = [-1, 0, 0, 1]
	dc = [0, -1, 1, 0]
	to = {}
	for r in xrange(n):
		for c in xrange(m):
			best = a[r][c]
			bestd = -1
			for d in xrange(4):
				r2 = r + dr[d]
				c2 = c + dc[d]
				if (r2 < 0 or r2 >= n or c2 < 0 or c2 >= m): continue
				lvl = a[r2][c2]
				if (lvl < best):
					best = lvl
					bestd = d
			if (bestd != -1):
				r2, c2 = r + dr[bestd], c + dc[bestd]
				if (r, c) not in to: to[(r, c)] = []
				to[(r, c)].append((r2, c2))
				if (r2, c2) not in to: to[(r2, c2)] = []
				to[(r2, c2)].append((r, c))
				
	res = {}
	color = 0
	for i in xrange(n):
		for j in xrange(m):
			if (i, j) in res: continue
			q = [(i, j)]
			qh = 0
			qt = 1
			color += 1
			res[(i, j)] = color
			while qh < qt:
				(r, c) = q[qh]
				qh += 1
				if not ((r, c) in to): continue
				for (r2, c2) in to[(r, c)]:
					if (r2, c2) in res: continue
					res[(r2, c2)] = color
					q.append((r2, c2))
					qt += 1
	
	print "Case #%d:" % (test + 1)
	for i in xrange(n):
		for j in xrange(m):
			print chr(res[(i, j)] + 96),
		print
	
	

for test in range(readint()):
	run_test(test)

