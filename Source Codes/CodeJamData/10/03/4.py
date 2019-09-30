tn = int(raw_input())
for loop in xrange(tn):
	R, k, N = [int(x) for x in raw_input().strip().split()]
	g = [int(x) for x in raw_input().strip().split()]
	next = [0] * N
	cost = [0] * N
	s = 0
	for i in xrange(N):
		s += g[i]
		if s > k:
			s -= g[i]
			next[0] = i
			cost[0] = s
			break
	else:
		print 'Case #%s: %s' % (loop+1, R*s)
		continue
	for i in xrange(1, N):
		s = cost[i-1] - g[i-1]
		for j in xrange(1,N+1):
			q = next[i-1] + j-1
			q %= N
			s += g[q]
			if s > k:
				s -= g[q]
				next[i] = q
				cost[i] = s
				break
	d = {}
	x = 0
	s = 0
	l = 0
	start_cycle = -1
	costsum = 0
	for i in xrange(min(N+1,R)):
		costsum += cost[x]
		if x in d:
			start_cycle = x
			ss, ll = d[x]
			start_cycle_len = ll
			start_cycle_cost = ss
			cycle_cost = s - ss
			cycle_len = l - ll
			break
		d[x] = (s, l)
		s += cost[x]
		l += 1
		x = next[x]

	if start_cycle != -1:
		costsum = start_cycle_cost
		remain = R - start_cycle_len
		times, still_remain = remain / cycle_len, remain % cycle_len
		costsum += times * cycle_cost
		x = start_cycle
		for i in xrange(still_remain):
			costsum += cost[x]
			x = next[x]

	print 'Case #%s: %s' % (loop+1, costsum)
