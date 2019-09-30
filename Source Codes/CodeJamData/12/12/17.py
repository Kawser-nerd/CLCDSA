for t in range(int(raw_input())):
	N = int(raw_input())
	levels = []
	
	for i in xrange(N):
		levels.append(map(int, raw_input().split()))
		
	r = 0
	s = 0
	while True:
		c = False
		
		for i in xrange(N):
			if levels[i][1] != -1 and levels[i][1] <= s:
				if levels[i][0] != -1:
					s += 1
				s += 1
				r += 1
				levels[i] = (-1, -1)
				c = True
				break
		if c:
			continue
		
		max_2v = -1
		max_2i = -1
		for i in xrange(N):
			if levels[i][0] != -1 and levels[i][0] <= s:
				if levels[i][1] > max_2v:
					max_2v = levels[i][1]
					max_2i = i
		if max_2v != -1:
			r += 1
			s += 1
			levels[max_2i][0] = -1
			continue
		
		break
					
	if s == N * 2:
		print 'Case #%d: %d' % (t + 1, r)
	else:
		print 'Case #%d: Too Bad' % (t + 1)
