import sys
import psyco
psyco.full()
def dbg(a): sys.stderr.write(str(a))
def readint(): return int(raw_input())
def readfloat(): return float(raw_input())
def readarray(foo): return [foo(x) for x in raw_input().split()]

def run_test(test):
	(n, k) = readarray(int)
	a = [list(reversed(raw_input().replace('.', ''))) for i in xrange(n)]
	check = {'R': False, 'B': False}
	for i in xrange(n):
		for j in xrange(len(a[i])):
			ok = [True, True, True, True]
			for t in xrange(k):
				for (s, r, c) in [(0, i, j + t), (1, i + t, j), (2, i + t, j + t), (3, i + t, j - t)]:
					if (r >= n or c < 0 or c >= len(a[r]) or a[r][c] != a[i][j]): ok[s] = False
			if (ok[0] or ok[1] or ok[2] or ok[3]):
				check[a[i][j]] = True
	res = 'Neither'
	if check['R'] and check['B']: res = 'Both'
	if check['R'] and not check['B']: res = 'Red'
	if not check['R'] and check['B']: res = 'Blue'
	print "Case #%d: %s" % (test + 1, res)

for test in range(readint()):
	dbg("Test %d\n" % (test + 1))
	run_test(test)
