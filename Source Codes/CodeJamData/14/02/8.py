T = int(raw_input())

for t in xrange(T):
	C, F, X = map(float, raw_input().split())
	R = 2
	total = 0

	while True:
		time = X/R
		tf = C/R + X/(R+F)
		if tf > time: break

		total += C/R
		R += F

	print "Case #%d: %.15f" %(t+1, total + X/R)
