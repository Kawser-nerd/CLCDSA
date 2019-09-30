from sys import *

from functools import *

def print_args(*args, **kwargs):
	return ','.join(value for value in [','.join(map(repr, args)),','.join("%s=%s" % (k, repr(v)) for k, v in kwargs.items())] if value)

def print_result(before=False, after=True):
	def fc(func):
		@wraps(func)
		def f(*args, **kwargs):
			if before:
				print "%s(%s)"      % (func.__name__, print_args(*args, **kwargs))
			r = func(*args, **kwargs)
			if after:
				print "%s(%s) = %s" % (func.__name__, print_args(*args, **kwargs), r)
			return r
		return f
	return fc

@print_result
def f(n):
	return 1 if n == 0 else n * f(n-1)


def tz(xs):
	return [s[i:] for s, i in xs]





from functools import wraps

mod = 10**9 + 7

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



from collections import *

@memoize
def Ch(n,r):
	if r < 0 or r > n: return 0
	if r == 0 or r == n: return 1
	return (Ch(n-1,r-1) + Ch(n-1,r)) % mod

z = input()

@memoize
#@print_result()
def fool(ss,a):
	if len(ss) < a:
		return -1,0
	if len(ss) == 1:
		s = ss[0]
		return len(s),1
	x,ct = feel(ss,a)
	for t in xrange(1,a):
		X,CT = fool(ss,t)
		CT *= Ch(a,t)
		CT %= mod
		if x == X:
			ct = (ct - CT) % mod
	return x,ct

@memoize
#@print_result()
def feel(ss,a):
	if len(ss) == 1:
		s = ss[0]
		return len(s),a
	cl = 0
	for s in ss:
		if not s:
			cl += 1
	d = defaultdict(list)
	for s in ss:
		if s:
			d[s[0]].append(s[1:])
	x,ct = 0,1
	for v in d.values():
		mx,mct = -1,0
		v = tuple(v)
		for t in xrange(1,a+1):
			X,CT = fool(v,t)
			if CT == 0: continue
			X += t
			CT *= Ch(a,t)
			CT %= mod
			if mx < X:
				mx = X
				mct = 0
			if mx == X:
				mct += CT
		x += mx
		ct *= mct
		ct %= mod
	ct *= pow(a, cl, mod)
	ct %= mod
	return x,ct
for cas in xrange(1,z+1):
	m, n = map(int, raw_input().strip().split())
	fool.memo.clear()
	feel.memo.clear()
	ss = []
	for i in xrange(m):
		ss.append(raw_input().strip())
	ss = tuple(ss)
	x,ct = fool(ss,n)
	x += n
	ct %= mod
	print >>stderr, cas, z
	print "Case #%s: %s %s" % (cas, x, ct)

