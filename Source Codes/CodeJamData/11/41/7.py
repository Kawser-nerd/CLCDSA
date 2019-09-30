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

def testCase():
	X, S, R, t, N = [int(v) for v in raw_input().split()]
	walkways = [[int(v) for v in raw_input().split()] for _ in xrange(N)]
	walkways.sort(key=lambda i:i[0])
	B_key = dict((walkway[0], walkway) for walkway in walkways)
	if R <= S:
		t = 0

	intervals = []
	p = 0
	while p != X:
		if not B_key:
			p_next = X
			speed = S
		elif p not in B_key:
			p_next = min(B_key.keys())
			speed = S
		else:
			p_next = B_key[p][1]
			speed = B_key[p][2] + S
			B_key.pop(p)
		intervals.append([p_next-p, speed])
		p = p_next

	result = 0.0
	for interval in sorted(intervals, key=lambda i:i[1]):
		t_walk = interval[0] / float(interval[1])
		t_run = interval[0] / (float(interval[1]) + R - S)
		if t >= t_run:
			result += t_run
			t -= t_run
		elif t > 0:
			p_run = float(t) / t_run
			result += t + (1 - p_run) * t_walk
			t = 0
		else:
			result += t_walk
	return result

if __name__ == '__main__':
	for i in xrange(int(raw_input())):
		print "Case #%d: %r" % (i + 1, testCase())
