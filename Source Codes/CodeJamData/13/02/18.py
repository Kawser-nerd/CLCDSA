T = input()
for t in range(T):
	N,M = map(int,raw_input().split())
	B = []
	for y in range(N):
		B += [map(int,raw_input().split())]
	F = [[False]*M for i in range(N)]
	
	for d in range(128):
		for y in range(N):
			f = True
			for x in range(M):
				if not F[y][x] and B[y][x]!=d:
					f = False
			if f:
				for x in range(M):
					F[y][x] = True
		for x in range(M):
			f = True
			for y in range(N):
				if not F[y][x] and B[y][x]!=d:
					f = False
			if f:
				for y in range(N):
					F[y][x] = True
	
	f = True
	for y in range(N):
		for x in range(M):
			if not F[y][x]:
				f = False
	ans = "YES" if f else "NO"
	
	print "Case #%s: %s"%(t+1,ans)
