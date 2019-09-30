import sys
import psyco
psyco.full()
def dbg(a): sys.stderr.write(str(a))
def readint(): return int(raw_input())
def readfloat(): return float(raw_input())
def readarray(foo): return [foo(x) for x in raw_input().split()]




def run_test(test):
	global mem, a
	(L, N) = readarray(int)
	INF = L + 1
	a = readarray(int)
	m = max(a)
	dp = dict([(x, 1) for x in a])
	K = 50000
	for i in xrange(K + 1000):
		r = dp[i] if i in dp else INF
		for x in a:
			if (i - x) in dp:
				r = min(r, dp[i - x] + 1)
		if r < INF:
			dp[i] = r

	div = int((L - K) / m)
	res = div
	left = L - div * m
	return res + dp[left] if left in dp else "IMPOSSIBLE"

for test in range(readint()):
	dbg("Test %d\n" % (test + 1))
	print "Case #%d: %s" % (test + 1, run_test(test))
	
