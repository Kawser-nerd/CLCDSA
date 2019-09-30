T = int(raw_input())

for t in xrange(T):
	a = int(raw_input())
	for k in xrange(4):
		s = set(map(int, raw_input().split()))
		if k+1 == a: ss = s

	a = int(raw_input())
	for k in xrange(4):
		s = set(map(int, raw_input().split()))
		if k+1 == a: ss &= s

	print "Case #%s:" % (t+1),
	if len(ss) > 1: print "Bad magician!"
	elif not ss: print "Volunteer cheated!"
	else: print list(ss)[0] 
