def run(x, r, c, k):
	a = [[0] * c for i in range(r)]
	for i in range(r):
		for j in range((i & 1) ^ x, c, 2):
			if i > 0:
				a[i - 1][j] += 1
			if j > 0:
				a[i][j - 1] += 1
			if i + 1 < r:
				a[i + 1][j] += 1
			if j + 1 < c:
				a[i][j + 1] += 1
	b = [j for i in a for j in i]
	b.sort()
	return sum(b[:k])

n = input()
for i in range(1, n + 1):
	r, c, k = [int(x) for x in raw_input().split()]
	ans = min(run(0, r, c, k), run(1, r, c, k))
	print "Case #%d: %d" % (i, ans)
