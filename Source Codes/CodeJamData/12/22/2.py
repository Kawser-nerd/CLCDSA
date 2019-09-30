def testCase():
	H, N, M = [int(v) for v in raw_input().split()]
	C = [[int(v) for v in raw_input().split()] for _ in xrange(N)]
	assert all(len(row) == M for row in C)
	F = [[int(v) for v in raw_input().split()] for _ in xrange(N)]
	assert all(len(row) == M for row in F)

	cost = [[1000000000]*M for _ in xrange(N)]

	def walk(t, x, y, tx, ty):
		water_level = max(1, H if t <= 0 else H-t)
		c1 = C[y][x]
		f1 = F[y][x]
		c2 = C[ty][tx]
		f2 = F[ty][tx]
		if f2 + 50 > c2:
			return
		if f1 + 50 > c2:
			return
		if f2 + 50 > c1:
			return
		if water_level + 50 > c2:
			tt = water_level + 50 - c2 + max(0, t)
			water_level_2 = max(1, H-tt)
		else:
			tt = t
			water_level_2 = water_level
		tt += 10
		if water_level_2 - f1 < 20:
			tt += 90
		if tt < cost[ty][tx]:
			cost[ty][tx] = tt
			schedule.append((tt, tx, ty))

	schedule = [(-10000000, 0, 0)]
	while schedule:
		schedule.sort(reverse=True)
		t, x, y = schedule.pop()
		if x > 0:
			walk(t, x, y, x-1, y)
		if x < M - 1:
			walk(t, x, y, x+1, y)
		if y > 0:
			walk(t, x, y, x, y-1)
		if y < N - 1:
			walk(t, x, y, x, y+1)

	t = cost[N-1][M-1]
	return max(0,t)*0.1

if __name__ == '__main__':
	n = int(raw_input())
	for i in xrange(n):
		print "Case #%d: %.1f" % (i+1, testCase())
