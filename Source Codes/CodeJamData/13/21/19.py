for test in range(input()):
	A,N = map(int,raw_input().split())
	M = map(int,raw_input().split())
	M.sort()
	T = [0]*(N+1)
	T[0] = A
	for i in range(1,N+1):
		T[i] = T[i-1]+T[i-1]-1
	for m in M:
		P = T
		T = [0]*(N+1)
		for i in range(N+1):
			if m<P[i]:
				T[i] = max(T[i],P[i]+m)
			if i<N:
				T[i+1] = max(T[i+1],P[i])
		for i in range(N):
			T[i+1] = max(T[i+1],T[i]*2-1)
	ans = 0
	for i in range(N+1):
		if T[i]>0:
			ans = i
			break
	print "Case #%s: %s"%(test+1,ans)
