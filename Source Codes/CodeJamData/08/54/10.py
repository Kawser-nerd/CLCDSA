n = input()
for loop in range(1, n+1):
		print "Case #%d:" % loop,
		H, W, R = [int(x) for x in raw_input().split()]
		os = {}
		for i in xrange(R):
			x, y = [int(t) for t in raw_input().split()]
			x-=1
			y-=1
			X = x
			Y = y
			if (x+y)%3 == 0:
				m = x+y
				h = m / 3
				x = y-h
				if x >= 0 and x <= h:
					os[(X,Y)]=1
		b = [[0]*100 for i in xrange(100)]
		q = [(0,0)]
		b[0][0] = 1
		visit = {}
		if (H-1+W-1)%3 != 0:
			print 0
			continue
		while q:
			x = q.pop(0)
			b[x[0]][x[1]] = b[x[0]][x[1]] %  10007
			if x[0] == H-1 and x[1] == W-1:
				print b[H-1][W-1]
				q.append(3)
				break
			if x in visit:
				continue
			visit[x] = 1
			if (x[0]+1, x[1]+2) not in os and x[0]+1 < H and x[1]+2 < W:
				b[x[0]+1][x[1]+2] += b[x[0]][x[1]]
				q.append((x[0]+1, x[1]+2))
			if (x[0]+2, x[1]+1) not in os and x[0] + 2 < H and x[1]+1 < W:
				b[x[0]+2][x[1]+1] += b[x[0]][x[1]]
				q.append((x[0]+2, x[1]+1))
		if not q:
			print 0

