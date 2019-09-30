tn = int(raw_input())
for loop in xrange(tn):
	n, k = raw_input().split()
	n = int(n)
	k = int(k)
	x = 2**n
	on = False
	if k % x == x-1:
		on = True
	print 'Case #%s: %s' % (loop+1, ['OFF','ON'][on])
