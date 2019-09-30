T = int(raw_input())
for case in range(T):
	N, K = map(int, raw_input().split())
	grid2 = [''] * N
	for i in range(N):
		for ch in raw_input():
			if ch != '.':
				grid2[i] = ch + grid2[i]
		while len(grid2[i]) < N:
			grid2[i] += '.'
	
	winR = False
	winB = False
	
	di = [-1,-1,-1,0,1,1,1,0]
	dj = [-1,0,1,1,-1,0,1,-1]
	
	for i in range(N):
		for j in range(N):
			#try finding something from this
			if grid2[i][j] == '.': continue
			for dir in range(8):
				ci, cj = i,j
				fail = False
				for steps in range(K):
					if ci >= 0 and cj >= 0 and ci < N and cj < N and grid2[ci][cj] == grid2[i][j]:
						ci += di[dir]
						cj += dj[dir]
					else:
						fail = True
						break	
				if not fail:
					if grid2[i][j] == 'B':
						winB = True
					else:
						winR = True
	
	s = 'Neither'
	if winR and winB:
		s = 'Both'
	elif winR:
		s = 'Red'
	elif winB:
		s = 'Blue'
	print "Case #%d: %s" % (case+1, s)