import sys
def dbg(a): sys.stderr.write(str(a))
def readint(): return int(raw_input())
def readfloat(): return float(raw_input())
def readarray(foo): return map(foo, raw_input().split())


def put(r, c, d):
	global q, qh, qt, dist
	if r < 0 or r >= n or c < 0 or c >= m: return
	if not a[r][c]: return
	if dist[r][c] >= 0: return
	dist[r][c] = d
	q.append((r, c))
	qt += 1

	
for test in range(readint()):
	dbg("Test %d\n" % (test + 1))
	n, m = readarray(int)
	a = []
	dist = []
	r1, c1 = 0, 0
	for i in xrange(n):
		s = raw_input()
		a.append([])
		dist.append([])
		for j in xrange(m):
			c = s[j]
			a[i].append(c != '.')
			dist[i].append(-1)
			if (c == 'T' and (i + j) > 0):
				r1, c1 = i, j
	
	dr = [-1, 1, 0, 0]
	dc = [0, 0, -1, 1]

	dist[0][0] = 0
	q = [(0, 0)]
	qh = 0
	qt = 1
	while qh < qt:
		(r, c) = q[qh]
		d = dist[r][c] + 1
		for i in xrange(4):
			put(r + dr[i], c + dc[i], d)
		qh += 1

	dist1 = dist[r1][c1]

	for i in xrange(n):
		for j in xrange(m):
			dist[i][j] = -1

	
	dist[0][0] = 0
	dist[r1][c1] = 0
	q = [(0, 0), (r1, c1)]
	qh = 0
	qt = 2
	while qh < qt:
		(r, c) = q[qh]
		d = dist[r][c] + 1
		for i in xrange(4):
			put(r + dr[i], c + dc[i], d)
		qh += 1
	
	res = 0
	for i in xrange(n):
		for j in xrange(m):
			if not a[i][j]: continue
			res += dist[i][j]
	
	p = int(dist1 / 2)
	if dist1 % 2 > 0:
		for i in xrange(p + 1): res -= 2 * i
	else:
		for i in xrange(p): res -= 2 * i
		res -= p
	for i in xrange(dist1 + 1):
		res += i
	
	print "Case #%d: %d" % (test + 1, res)
