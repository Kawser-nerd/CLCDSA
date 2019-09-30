for T in xrange(input()):
	N = input()
	L = []
	for i in xrange(N):
		a,b = map(int,raw_input().split())
		L.append([b,a])
	L.sort()
	print "Case #%d:"%(T+1),
	s = 0
	n = 0
	while L:
		if L[0][0]<=s:
			b,a = L.pop(0)
			s += 1
			if a!=float('inf'): s += 1
		else:
			for i in xrange(len(L)-1,-1,-1):
				if L[i][1]<=s:
					s += 1
					L[i][1] = float('inf')
					break
			else:
				print "Too Bad"
				break
		n+=1
	else: print n
