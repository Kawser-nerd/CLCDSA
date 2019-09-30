def isset(a, bit): return ((a >> bit) & 1) > 0
def readint(): return int(raw_input())
def readfloat(): return float(raw_input())
def readarray(N, foo):
	res = []
	for i in xrange(N):
		res.append(foo())
	return res
def readlinearray(foo): return map(foo, raw_input().split())

def gen(n, A, B, C, D, x0, y0, M):
	(x, y) = (x0, y0)
	res = []
	for i in xrange(n):
		res.append((x, y))
		x = (A * x + B) % M
		y = (C * y + D) % M
	return res
		
def run_test():
	(n, A, B, C, D, x0, y0, M) = readlinearray(int)
	points = gen(n, A, B, C, D, x0, y0, M)
	res = 0
	counts = [0, 0, 0, 0, 0, 0, 0, 0, 0]
	for (x, y) in points:
		counts[(x % 3) * 3 + (y % 3)] += 1
	res = 0
	for i in xrange(0, 9):
		for j in xrange(i, 9):
			for k in xrange(j, 9):
				x = (i / 3) + (j / 3) + (k / 3)
				y = (i % 3) + (j % 3) + (k % 3)
				if x % 3 != 0 or y % 3 != 0: continue
				if (i == j and j == k):
					r = counts[i] * (counts[i] - 1) * (counts[i] - 2) / 6
				elif i == j:
					r = counts[i] * (counts[i] - 1) * counts[k] / 2
				elif i == k:
					r = counts[i] * (counts[i] - 1) * counts[j] / 2
				elif j == k:
					r = counts[i] * (counts[j] - 1) * counts[j] / 2
				else:
					r = counts[i] * counts[j] * counts[k]
				res += r
	return res

if __name__ == "__main__":
	tests = int(raw_input())
	for test in range(tests):
		res = run_test()
		print "Case #%d: %s" % (test + 1, res)

