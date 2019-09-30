for test in range(input()):
	N,p,q,r,s = map(int, raw_input().split())
	D = [(i*p+q)%r+s for i in range(N)]
	S = sum(D)
	ans = S
	A,B,C = 0,0,S
	a = 0
	b = -1
	while b<N-1:
		b += 1
		C -= D[b]
		B += D[b]
		p = max(A,B,C)
		while a<b:
			B -= D[a]
			A += D[a]
			a += 1
			t = max(A,B,C)
			if t>=p:
				a -= 1
				B += D[a]
				A -= D[a]
				break
			p = t
		ans = min(ans, p)
	ans = float(S-ans)/S
	print "Case #%s: %.16f" % (test+1, ans)
