def path(a, b, c, d, e):
	if (a, b) == (c, d):
		return True
	if not (0 <= a < R) or not (0 <= b < C):
		if ga != a or gb != b:
			return False
	if e == 0:
		if X[(a + 1) % R][b] == 0:
			return path(a + 1, b, c, d, 1)
		else:
			return path(a + 1, b, c, d, 3)
	if e == 1:
		if X[a][b - 1] == 0:
			return path(a, b - 1, c, d, 0)
		else:
			return path(a, b - 1, c, d, 2)
	if e == 2:
		if X[a - 1][b] == 0:
			return path(a - 1, b, c, d, 3)
		else:
			return path(a - 1, b, c, d, 1)
	if e == 3:
		if X[a][(b + 1) % C] == 0:
			return path(a, b + 1, c, d, 2)
		else:
			return path(a, b + 1, c, d, 0)

for case in xrange(1, input() + 1):
	R, C = map(int, raw_input().split())
	T = [0 for i in xrange((R + C) * 2)]
	for i, x in enumerate(map(int, raw_input().split())):
		if i % 2 == 0:
			y = x
		else:
			T[y - 1] = x - 1
			T[x - 1] = y - 1
	pts = []
	for i in xrange((R + C) * 2):
		if i < C:
			pts.append([0, -1, i])
		elif i < C + R:
			pts.append([1, i - C, C])
		elif i < 2 * C + R:
			pts.append([2, R, R + C + C - i - 1])
		else:
			pts.append([3, R + C + C + R - i - 1, -1])
	X = [[0 for i in xrange(C)] for j in xrange(R)]
	hue = R * C
	print "Case #" + str(case) + ":"
	for j in xrange(2 ** (hue)):
		direc = map(int, bin(j)[2:].zfill(hue))
		X = []
		for r in xrange(R):
			X.append(direc[r * C:(r + 1) * C])
		for i, x in enumerate(T):
			ga, gb = pts[i][1], pts[i][2]
			if i < x and (not path(pts[i][1], pts[i][2], pts[x][1], pts[x][2], pts[i][0])):
				break
		else:
			for x in X:
				print ''.join(['/', '\\'][y] for y in x)
			break
	else:
		print "IMPOSSIBLE"