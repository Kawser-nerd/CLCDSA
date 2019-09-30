def pos(x):
	if x == 0:
		return all([x for x in jobs])
	worked = False
	for i in xrange(N):
		if workers[i] == 0:
			workers[i] = 1
			for j in xrange(N):
				if G[i][j] == 1 and jobs[j] == 0:
					worked = True
					jobs[j] = 1
					if not pos(x - 1):
						return False
					jobs[j] = 0
			workers[i] = 0
	if not worked:
		return pos(x - 1)
	return True



for case in xrange(1, input() + 1):
	N = input()
	G = []
	for _ in xrange(N):
		G.append(map(int, raw_input().strip()))
	ans = 0
	off = []
	for i in xrange(N):
		for j in xrange(N):
			if G[i][j] == 0:
				off.append([i, j])
	ans = N * N
	loff = len(off)
	for i in xrange(2 ** loff):
		extra = 0
		for j, x in enumerate(bin(i)[2:].zfill(loff)):
			if x == '1':
				G[off[j][0]][off[j][1]] = 1
				extra += 1
		jobs = [0 for ii in xrange(N)]
		workers = [0 for ii in xrange(N)]
		if pos(N):
			ans = min(ans, extra)
		for j, x in enumerate(bin(i)[2:].zfill(loff)):
			if x == '1':
				G[off[j][0]][off[j][1]] = 0
	print "Case #" + str(case) + ":",
	print ans