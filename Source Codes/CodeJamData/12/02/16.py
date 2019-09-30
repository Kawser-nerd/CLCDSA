

T = int(raw_input())

for t in xrange(1,T+1):
	line = raw_input()
	ints = map(int, line.split())
	N = ints.pop(0)
	S = ints.pop(0)
	p = ints.pop(0)
	c = 0
	for i in ints:
		if i==0:
			lo = hi = 0
		else:
			r = i%3
			if r==0:
				lo = i/3
				hi = lo + 1
			elif r==1:
				lo = hi = (i+2)/3
			elif r==2:
				lo = (i+1)/3
				hi = lo + 1
		if lo >= p:
			c += 1
		elif hi >= p:
			if S > 0:
				c += 1
				S -= 1
	print 'Case #%s: %s'%(t,c)








