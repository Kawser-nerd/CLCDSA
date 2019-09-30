T = int(raw_input())
for TK in xrange(T):
	print 'Case #%d:' % (TK+1), 

	N, L = map(int, raw_input().split())
	G = raw_input().split()
	B = raw_input()
	if '1' * L in G:
		print 'IMPOSSIBLE'
		continue

	if L == 1:
		print '0 0?'
	else:
		a = '?' * (L-1)
		b = '10?1' + ('01' * L)
		print a, b
	