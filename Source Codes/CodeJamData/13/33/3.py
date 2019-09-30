T = input()

for case in range(1, T+1):
	N = input()
	d, n, w, e = [0] * N, [0] * N, [0] * N, [0] * N
	s, dd, dp, ds = [0] * N, [0] * N, [0] * N, [0] * N
	for i in range(N):
		[d[i],n[i],w[i],e[i],s[i],dd[i],dp[i],ds[i]] = map(int,raw_input().strip().split())


	q = []
	wall = {}
	changes = {}
	for i in range(-600, 600):
		wall[i] = 0
		changes[i] = 0

	for i in range(N):
		for j in range(n[i]):
			q.append((d[i]+dd[i]*j, i, j))

	q.sort()
	# print q

	succ = 0
	last_day = 0
	

	for a in q:
		[day, tr, dt] = a
		if day != last_day:
			for i in range(-600, 600):
				wall[i] = max(wall[i], changes[i])
				changes[i] = wall[i]
		
		cw, ce = w[tr] + dp[tr] * dt, e[tr] + dp[tr] * dt
		cs = s[tr] + ds[tr] * dt 

		if len(filter(lambda x: x < cs, [wall[i] for i in range(2*cw, 2*ce+1)])) > 0:
			succ += 1
			# print day, tr, dt

		for i in range(2*cw, 2*ce+1):
			if changes[i] < cs:
				changes[i] = cs

		last_day = day

	print "Case #%d: %d" % (case, succ)