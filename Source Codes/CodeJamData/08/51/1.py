def readint(): return int(raw_input())
def readfloat(): return float(raw_input())
def readarray(N, foo):
	res = []
	for i in xrange(N):
		res.append(foo())
	return res
def readlinearray(foo): return map(foo, raw_input().split())


def turnleft():
	global dx, dy
	(dx, dy) = (-dy, dx)
def turnright():
	global dx, dy
	(dx, dy) = (dy, -dx)
def movefront():
	global x, y
	if dx == 0:
		if dy == 1:
			left[(x, y)] = True
		else:
			left[(x, y - 1)] = True
	elif dx == 1:
		top[(x, y)] = True
	else:
		top[(x - 1, y)] = True
	x += dx
	y += dy
		
	
for test in range(int(raw_input())):
	dy = 1
	dx = 0
	x = 0
	y = 0


	t = readint()
	a = []
	while len(a) < t + t:
		s = raw_input()
		a += s.split(" ")
	i = 0
	ss = ""
	while i < len(a):
		s = a[i]
		l = int(a[i + 1])
		i += 2
		ss += s * l

	top = {}
	left = {}
	for c in ss:
		if c == 'L': turnleft()
		elif c == 'R': turnright()
		else: movefront()
	
	cleft = {}
	M = 110
	for y in xrange(-M, M):
		cur = 0
		for x in xrange(-M, M):
			if (x, y) in left: cur += 1
			cleft[(x, y)] = cur
	ctop = {}
	for x in xrange(-M, M):
		c = []
		cur = 0
		for y in xrange(-M, M):
			if (x, y) in top: cur += 1
			ctop[(x, y)] = cur

#	for y in xrange(-M, M):
#		s = ""
#		for x in xrange(-M, M):
#			c = 0
#			c += 1 if (x, y) in top else 0
#			c += 2 if (x, y) in left else 0
#			s += ('.', '-', '|', '+')[c]
#		print s
	
	res = 0
	for y in xrange(-M, M):
		for x in xrange(-M, M):
			ct = ctop[(x, y)]
			cb = ctop[(x, M - 1)] - ct
			cl = cleft[(x, y)]
			cr = cleft[(M - 1, y)] - cl
			if (ct % 2 != 0 or cl % 2 != 0): continue
			if (cl > 0 and cr > 0) or (ct > 0 and cb > 0): res += 1

	print "Case #%d: %s" % (test + 1, res)
