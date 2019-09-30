def find(a):
	for i in xrange(2, 6):
		for j in xrange(2, 6):
			for k in xrange(2, 6):
				products = set([1, i, j, k, i * j, i * k, j * k, i * j * k])
				for x in a:
					if x not in products: break
				else:
					return "%d%d%d" % (i, j, k)
	return "222"

def solve():
	R, N, M, K = map(int, raw_input().split())
	res = []
	for i in xrange(R):
		a = map(int, raw_input().split())
		res.append(find(a))
	return "\n".join(res)

for i in xrange(input()):
	print "Case #%d:\n%s" % (i + 1, solve())
