from sys import *
z = input()
for cas in xrange(1, z + 1):
	r, t = map(int, raw_input().strip().split())
	L, R = 0, t + 2
	while R - L > 1:
		n = L + R >> 1
		if n * (2 * r + 1) + 2 * n * (n - 1) <= t:
			L = n
		else:
			R = n
	print "Case #%d: %d" % (cas, L)