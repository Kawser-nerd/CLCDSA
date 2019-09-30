t = int(raw_input())

def left(l):
	return [x[:len(x)/2] for x in l[1:]]
def right(l):
	return [x[len(x)/2:] for x in l[1:]]

class Tree:
	def __init__(self, arr):
		self.value = arr[0][0]
		if len(arr) > 1:
			self.left, self.right = Tree(left(arr)), Tree(right(arr))

def min_money(m,c):
	if len(m) == 2:
		if m[0] <= 0 and m[1] <= 0:
			return 0
		elif m[0] <= 1 and m[1] <= 1:
			return c.value
		else:
			return 2000000000

	a = min_money(m[:len(m)/2], c.left) + min_money(m[len(m)/2:], c.right)
	m1 = [x-1 for x in m]
	b = c.value + min_money(m1[:len(m1)/2], c.left) + min_money(m1[len(m1)/2:], c.right)
	return min(a,b)

for i in xrange(t):
	p = int(raw_input())
	m = map(int,raw_input().split())
	m = [p-x for x in m]
	c = [map(int,raw_input().split()) for j in xrange(p)]
	c.reverse()
	print "Case #%d: %d" % (i+1, min_money(m,Tree(c)))
