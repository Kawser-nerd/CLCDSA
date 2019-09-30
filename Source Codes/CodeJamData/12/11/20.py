for t in range(int(raw_input())):
	A, B = map(int, raw_input().split())
	p = map(float, raw_input().split())
	
	prob = 1
	r = B + 2
	for backspace, i in zip(xrange(A, -1, -1), xrange(-1, A)):
		if i != -1:
			prob *= p[i]
		
		r = min(r, (2 * backspace + B - A + 1) + (1 - prob) * (B + 1))
	
	print 'Case #%d: %.9f' % (t + 1, r)
