def gcd(a,b):
	return gcd(b, a%b) if b else a

tn = int(raw_input())
for loop in xrange(tn):
	line = raw_input()
	d = [int(x) for x in line.strip().split()[1:]]
	g = -1
	for i in xrange(len(d)):
		for j in xrange(i+1, len(d)):
			if g == -1:
				g = abs(d[i]-d[j])
			else:
				g = gcd(g, abs(d[i]-d[j]))
	x = (g - d[0] % g)%g
			
	print 'Case #%s: %s' % (loop+1, x)
