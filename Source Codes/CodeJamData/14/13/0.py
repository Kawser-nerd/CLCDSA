T = int(raw_input())

for t in xrange(1,T+1):
	print "Case #%d:" % t,

	raw_input()
	A = map(int, raw_input().split())

	s = sum(y<i for i,y in enumerate(A))
	if s < 484: print "BAD"
	else: print "GOOD"