get = lambda: map(int, raw_input().split())

def memo(f):
	cache = dict()
	def wrap(*args):
		if args not in cache:
			cache[args] = f(*args)
		return cache[args]
	return wrap



T, = get()

for testCase in range(1, T+1):

	N, = get()
	A = get()

	swaps = 0
	while A:
		m = min(A)
		i = A.index(m)
		swaps += min(i, len(A) - 1 - i)
		A.pop(i)

	print 'Case #%d: %d' % (testCase, swaps)