T = int(raw_input())
for i in range(1, T + 1):
	j, p, s, k = [int(x) for x in raw_input().split()]
	print "Case #%d:" % i, j * p * min(s, k)
	ans = [(x, y) for x in range(1, j + 1) for y in range(1, p + 1) for t in range(min(s, k))]
	now = 0
	last = -1
	for i in ans:
		if i[0] != last:
			now = i[0] - 1
			last = i[0]
		print i[0], i[1], now % s + 1
		now += 1