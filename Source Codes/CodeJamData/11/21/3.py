T = input()
for case in range(T):
	N = input()
	A = [raw_input() for i in range(N)]
	WP = [0.0]*N
	C = [0]*N
	for i in range(N):
		for j in range(N):
			if A[i][j]!=".": C[i]+=1
			if A[i][j]=="1": WP[i]+=1
		WP[i] /= C[i]
	
	OWP = [0.0]*N
	for i in range(N):
		for j in range(N):
			if A[i][j]=="1": OWP[i]+=WP[j]*C[j]/(C[j]-1)
			if A[i][j]=="0": OWP[i]+=(WP[j]*C[j]-1)/(C[j]-1)
		OWP[i] /= C[i]
	
	OOWP = [0.0]*N
	for i in range(N):
		for j in range(N):
			if A[i][j]!=".": OOWP[i]+=OWP[j]
		OOWP[i] /= C[i]
	"""
	print WP
	print OWP
	print OOWP
	"""
	
	print "Case #%s:" % (case+1)
	for i in range(N):
		print "%.20f"%(0.25*WP[i]+0.50*OWP[i]+0.25*OOWP[i])

