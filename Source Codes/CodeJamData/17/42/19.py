for t in range(int(input())):
	n, c, m = (int(i) for i in input().split())
	raw = [[0] * c for i in range(n)]
	for i in range(m):
		p, b = (int(i) for i in input().split())
		raw[p - 1][b - 1] += 1
	to = [0] * n
	max = 0
	for i in range(n):
		tp = 0
		for j in range(c):
			to[i] += raw[i][j]
			if i != 0:
				raw[i][j] = raw[i][j] + raw[i - 1][j]
			if raw[i][j] > max:
				max = raw[i][j]
			tp += raw[i][j]
		avg = (tp - 1) // (i + 1) + 1
		if avg > max:
			max = avg
	p = 0
	for i in range(n):
		if to[i] > max:
			p += to[i] - max
	print("Case #%d: %d %d" % (t + 1, max, p))