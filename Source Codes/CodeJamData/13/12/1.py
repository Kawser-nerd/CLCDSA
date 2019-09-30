from sys import *
z = input()
from functools import wraps

def memoize(function):
	memo = {}
	@wraps(function)
	def f(*args, **kwargs):
		key = args, tuple(sorted(kwargs.items()))
		if key not in memo:
			memo[key] = function(*args, **kwargs)
		return memo[key]
	f.memo = memo
	return f


for cas in xrange(1, z + 1):
	e, r, n = map(int, raw_input().strip().split())
	v = map(int, raw_input().strip().split())

	@memoize
	def f(E, N):
		if N == n:
			return 0
		s = 0
		for t in xrange(E + 1):
			w = f(min(e, E - t + r), N + 1) + t * v[N]
			s = max(s, w)

		return s
	f.memo.clear()

	ans = f(e, 0)

	print "Case #%d: %d" % (cas, ans)