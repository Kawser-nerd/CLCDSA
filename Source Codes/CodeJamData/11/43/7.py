import math
from math import sqrt

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

def gcd_stein(a, b):
	assert a >= 0
	assert b >= 0
	if a == 0:
		return b
	k = 0
	while a & 1 == 0 and b & 1 == 0:
		k += 1
		a >>= 1
		b >>= 1
	if a & 1:
		t = -b
	else:
		t = a
	while t:
		while abs(t) & 1 == 0:
			t >>= 1
		if t > 0:
			a = t
		else:
			b = -t
		t = a -b
	return a * (1 << k)

def gen_sieve_primes_2(limit):
	limit_1 = (int(sqrt(limit)) + 1) // 2
	limit_2 = (limit + 1) // 2
	sieve = [True] * limit_2
	if 2 <= limit:
		yield 2
	for i in xrange(1, limit_1):
		if sieve[i]:
			candidate = i * 2 + 1
			yield candidate
			start = 2*(i*i+i)
			assert start < limit_2
			for non_prime in xrange(start, limit_2, candidate):
				sieve[non_prime] = False
	for i in xrange(limit_1, limit_2):
		if sieve[i]:
			yield i*2+1

def stupidSolve(N):
	n = int(math.ceil(N**0.5) + 1)
	result = int(N > 1)
	for p in gen_sieve_primes_2(n):
		n = p*p
		while n <= N:
			result += 1
			n *= p
	return result

def testCase():
	N = int(raw_input())
	return stupidSolve(N)

if __name__ == '__main__':
	for i in xrange(int(raw_input())):
		print "Case #%d: %s" % (i + 1, testCase())
