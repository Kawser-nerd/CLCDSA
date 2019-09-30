def solve(m,p):
	global H
	if max(H)<=0:
		return m
	r = 0
	C = range(p,N+1)
	
	for i in range(N):
		if H[i]>0:
			break
	if i<p and H[i]-P<=0:
		C = [i]+C
	
	for i in C:
		if i==N or H[i]>0:
			t = m
			if i<N:
				H[i] -= P
				if H[i]<=0:
					t += G[i]
			
			j = 0
			while j<N:
				if H[j]>0:
					break
				j += 1
			if j<N:
				H[j] -= Q
			
			r = max(r, solve(t,i))
			
			if j<N:
				H[j] += Q
			if i<N:
				H[i] += P
	return r

for test in range(input()):
	global P,Q,N,H,G
	P,Q,N = map(int, raw_input().split())
	H,G = [], []
	for i in range(N):
		h,g = map(int, raw_input().split())
		H += [h]
		G += [g]
	print "Case #%s: %s" % (test+1, solve(0,0))
