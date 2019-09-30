get = lambda: map(int, raw_input().split())

T, = get()

for case in range(1, T+1):
	N, X = get()
	s = sorted(get())
	l = len(s) - 1
	f = 0
	d = 0
	while l >= f:
		if l == f:
			d += 1
			l -= 1
		else:
			if s[l] + s[f] <= X:
				d += 1
				l -= 1
				f += 1
			else:
				d += 1
				l -= 1
	print 'Case #%d: %d' % (case, d)