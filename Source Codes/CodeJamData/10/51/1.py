import sys
import psyco
psyco.full()
def dbg(a): sys.stderr.write(str(a))
def readint(): return int(raw_input())
def readfloat(): return float(raw_input())
def readarray(foo): return [foo(x) for x in raw_input().split()]


def egcd(a, b):
	if a % b == 0: return (0, 1)
	t = egcd(b, a % b)
	return (t[1], t[0] - t[1] * (a / b))

def inverse(x, p):
	r = egcd(x, p)[0]
	if (r < 0): r += p
	return r

def sieve(N):
	bad = {}
	yield 2
	for i in xrange(3, N, 2):
		if i in bad: continue
		yield i
		j = i * i
		while j < N:
			bad[j] = True
			j += i

primes = {}
for i in xrange(1, 7):
	primes[i] = list(sieve(10 ** i))

def check(s, p, a):
	next = (s[0] * a) % p
	b = (s[1] - next + p) % p
	cur = s[0]
	for i in xrange(1, len(s)):
		cur = (cur * a + b) % p
		if cur != s[i]: return -1
	return (cur * a + b) % p
			
def run_test(test):
	(D, K) = readarray(int)
	s = readarray(int)
	m = max(s)
	if (len(s)) == 1: return "I don't know."
	res = -1
	for p in primes[D]:
		if p <= m: continue
		if len(s) > 2:
			d1 = (s[1]-s[0]+p)%p
			d2 = (s[2]-s[1]+p)%p
			if d1 == 0 and d2 == 0:
				as = [0]
			elif d1 == 0 or d2 == 0:
				return s[2]
			else:
				as = [(inverse(d1, p) * d2) % p]
		elif len(s) == 2 and s[0] == s[1]:
			return s[0]
		else:
			as = xrange(p)
		for a in as:
			r = check(s, p, a)
			if r == -1: continue
			if (res == -1):
				res = r
				continue
			if (res != r):
				return "I don't know."
	return res

for test in range(readint()):
	dbg("Test %d\n" % (test + 1))
	print "Case #%d: %s" % (test + 1, run_test(test))
	
