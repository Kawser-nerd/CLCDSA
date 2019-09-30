t=input()
for _ in range(t):
	print "Case #"+str(_+1)+":"
	n=input()
	s=[""]*n
	for i in range(n):
		s[i]=raw_input()
	
	wp=[0.0]*n
	for i in range(n):
		cnt=0
		win=0
		for j in range(n):
			if s[i][j]=='0':
				cnt+=1
			elif s[i][j]=='1':
				cnt+=1
				win+=1
		wp[i]=win*1.0/cnt
	
	owp=[0.0]*n
	for i in range(n):
		op=0
		for j in range(n):
			if i!=j and s[i][j]!='.':
				op+=1
				cnt=0
				win=0
				for k in range(n):
					if k!=i:
						if s[j][k]=='0':
							cnt+=1
						elif s[j][k]=='1':
							cnt+=1
							win+=1
				owp[i]+=win*1.0/cnt
		owp[i]/=op

	oowp=[0.0]*n
	for i in range(n):
		op=0
		for j in range(n):
			if i!=j and s[i][j]!='.':
				op+=1
				oowp[i]+=owp[j]
		oowp[i]/=op
	
	for i in range(n):
		print 0.25*wp[i]+0.5*owp[i]+0.25*oowp[i]
