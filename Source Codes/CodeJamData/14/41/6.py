T = int(raw_input())

for t in xrange(1,T+1):
	print "Case #%d:" % t,

	N, X = map(int,raw_input().split())

	sz = map(int,raw_input().split())
	sz.sort()

	sm = 0
	l = len(sz)-1
	tot = 0
	while l > sm:
		if sz[l]+sz[sm] <= X:
			l-=1
			sm+=1
		else:
			l -= 1
		tot += 1

	if l == sm: tot += 1

	print tot
