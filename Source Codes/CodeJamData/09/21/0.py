class Node:
	def __init__(self, p, f, l, r):
		self.p = p
		self.f = f
		self.l = l
		self.r = r
	def check(self, fs, p):
		p *= self.p
		if self.f in fs:
			return self.l.check(fs, p)
		else:
			return self.r.check(fs, p)

class Leaf:
	def __init__(self, p):
		self.p = p

	def check(self, _, p):
		return p * self.p

def build(a, s, e):
	if ' ' in a[s]:
		# node
		left, ln = build(a, s+1, e)
		right, rn = build(a, s+1+ln, e)
		p, f = a[s].split()
		p = float(p)
		return Node(p, f, left, right), 1+ln+rn
	else:
		# leaf
		return Leaf(float(a[s])), 1

def parse(s):
	a = [x.strip() for x in s.replace(')','').split('(') if x.strip()]
	return build(a, 0, len(a))[0]

if __name__ == '__main__':
	loopN = int(raw_input())
	for i in xrange(loopN):
		print 'Case #%d:' % (i+1)
		ln = int(raw_input())
		s = ''
		for j in xrange(ln):
			s += raw_input()
		howcute = parse(s)
		an = int(raw_input())
		for j in xrange(an):
			animal = raw_input().split()
			features = set(animal[2:])
			print "%.7f" % howcute.check(features, 1)

