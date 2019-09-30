for test in range(input()):
	N,X,Y = map(int,raw_input().split())
	X = abs(X)
	n = 1
	t = 1
	w = 0
	while True:
		t += 4
		if n+t>N:
			break
		n += t
		w += 1
	t = t/2
	if (X+Y)/2<=w:
		ans = 1.0
	elif (X+Y)/2>=w+2:
		ans = 0.0
	else:
		N -= n
		T = [1.0]+[0.0]*t
		for i in range(N):
			P = T
			T = [0.0]*(t+1)
			for j in range(t+1):
				if j==t:
					T[j] += P[j]
				elif i-j==t:
					T[j+1] += P[j]
				else:
					T[j] += P[j]/2
					T[j+1] += P[j]/2
		ans = sum(T[Y+1:])
		
	print "Case #%s: %.16f"%(test+1,ans)
