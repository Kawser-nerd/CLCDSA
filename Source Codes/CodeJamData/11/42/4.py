def cached(f):
	not_cached = object()
	cache = {}
	def wrapper(*args):
		result = cache.get(args, not_cached)
		if result is not not_cached:
			return result
		cache[args] = result = f(*args)
		return result
	wrapper.cache = cache
	return wrapper

def check(w, x0, y0, k):
	kr = xrange(0, k)

	ys = 0
	xs = 0
	ms = 0

	for y in kr:
		row = w[y0 + y]
		for x in kr:
			m = row[x0 + x]
			xs += m*x
			ys += m*y
			ms += m

	ms -= w[y0][x0] + w[y0 + k - 1][x0] + w[y0][x0 + k - 1] + w[y0 + k - 1][x0 + k - 1]
	xs -= (w[y0][x0 + k - 1] + w[y0 + k - 1][x0 + k - 1]) * (k - 1)
	ys -= (w[y0 + k - 1][x0] + w[y0 + k - 1][x0 + k - 1]) * (k - 1)

	# 1 2 3
	# 2 2 2
	# 3 2 1

	# xs 0 2 6 = 18
	#    0 2 4
	#    0 2 2

	# ys 0 0 0 = 18
	#    2 2 2
	#    6 4 2

	# ms 18

	# 3 * 2 * 2 = 
	c2 = k - 1
	#print k, xs, ys, ms, c2

	return xs * 2 == ys * 2 == ms * c2

def testCase():
	R, C, D = [int(v) for v in raw_input().split()]
	if R < 3 or C < 3:
		return "IMPOSSIBLE"
	w = [[int(v) for v in raw_input()] for _ in xrange(R)]

	for k in reversed(xrange(3, min(R, C)+1)):
		#print k
		for x0 in xrange(0, C-k+1):
			for y0 in xrange(0, R-k+1):
				if check(w, x0, y0, k):
					return k
	return "IMPOSSIBLE"

if __name__ == '__main__':
	for i in xrange(int(raw_input())):
		print "Case #%d: %s" % (i + 1, testCase())
