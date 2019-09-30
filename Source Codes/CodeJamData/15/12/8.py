import bisect

def howmany(M, t):
	'''how many people has started cutting hair at time t'''
	return sum((t // m) + 1 for m in M) if t >= 0 else 0

T = int(raw_input())

for test in xrange(T):
	B, N = map(int, raw_input().split())
	M = map(int, raw_input().split())
	a = -1
	b = 1
	while howmany(M, b) < N:
		b <<= 1
	while a < b: #?
		c = (a + b) // 2
		if howmany(M, c) < N:
			a = c + 1
		else:
			b = c
	served = howmany(M, a - 1)
	for i, m in enumerate(M):
		if a % m == 0:
			served += 1
			if served == N:
				ans = i
				break
	print "Case #{}: {}".format(test + 1, ans + 1)