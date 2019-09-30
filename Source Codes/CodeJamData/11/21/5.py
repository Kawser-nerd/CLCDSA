#!/usr/bin/python

T = int(raw_input())

def WP(a, i):
	c = 0
	s = 0
	for j in xrange(len(a[i])):
		if a[i][j] != -1:
			c += 1
			if a[i][j] == 1:
				s += 1
	return float(s) / float(c)

def OWP(a, i):
	cc = 0
	ss = 0
	for j in xrange(len(a[i])): 
		if a[i][j] != -1:
			c = 0
			s = 0
			for k in xrange(len(a[j])):
				if a[j][k] != -1 and k != i:
					c += 1
					if a[j][k] == 1:
						s += 1
			ss += float(s) / float(c)
			cc += 1
	return float(ss)/float(cc)

def RPI(a, i):
	res = 0.25 * WP(a, i) + 0.5 * OWP(a, i)
	oowp = 0
	c_oowp = 0
	for j in xrange(len(a[i])):
		if a[i][j] != -1:
			c_oowp += 1
			oowp += OWP(a, j)
	return res + 0.25 * (oowp / c_oowp)

for tt in xrange(1, T+1):
	n = int(raw_input())
	a = []
	for i in xrange(n): a.append([-1] * n)
	for i in xrange(n):
		s = raw_input()
		for j in xrange(n):
			if s[j] == '1': a[i][j] = 1
			elif s[j] == '0': a[i][j] = 0
	print "Case #%d:" % tt
	for i in xrange(n):
		print "%.9f" % RPI(a, i)
