#!/usr/bin/python

import sys, re

class Tree(object):
	def __init__(self, m):
		self.m = m
		self.cond = ""
		self.left = None
		self.right = None
	def __str__(self):
		if self.cond:
			return "<%f, [%s], %s, %s>" % (self.m, self.cond, str(self.left), str(self.right))
		else:
			return "<%f>" % self.m



def parse(expr):
	s = expr.strip()[1:-1]
	if s.find('(') == -1:
		return Tree(float(s))
	i = 0
	while s[i] != '(': i += 1
	(prob, feature) = s[:i].split()
	t = Tree(float(prob))
	t.cond = feature
	c = 1
	j = i+1
	while c:
		if s[j] == '(':
			c += 1
		elif s[j] == ')':
			c -= 1
		j += 1
	t.left = parse(s[i:j])
	i = j
	while s[i] != '(': i += 1
	c = 1
	j = i+1
	while c:
		if s[j] == '(':
			c += 1
		elif s[j] == ')':
			c -= 1
		j += 1
	t.right = parse(s[i:j])
	return t

f = sys.stdin

n = int(f.readline())

for test in xrange(n):
	l = int(f.readline())
	expr = ""
	for i in xrange(l):
		expr += " " + f.readline().strip() + " "
	expr = expr.strip()
	T = parse(expr)
	#print T
	a = int(f.readline())
	print "Case #%d:" % (test + 1,)
	for i in xrange(a):
		line = f.readline().strip()
		features = line.split()[2:]
		t = T
		prob = 1.0
		while t.cond != "":
			prob *= t.m
			if t.cond in features:
				t = t.left
			else:
				t = t.right
		prob *= t.m
		print "%.7f" % prob
