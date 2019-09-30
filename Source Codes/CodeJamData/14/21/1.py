T=int(raw_input())
for Case in xrange(T):
	print 'Case #%d:'%(Case+1),
	N=int(raw_input())
	def tonormal(x):
		a=[]
		for i in x:
			if len(a)==0 or a[-1][0]!=i:
				a.append((i,1))
			else:
				a[-1]=(a[-1][0],a[-1][1]+1)
		return a
	A=[tonormal(raw_input()) for i in xrange(N)]
	win=all([[j[0] for j in A[0]] == [j[0] for j in A[k]] for k in xrange(1,N)])
	if win:
		s=0
		for i in xrange(len(A[0])):
			t=[A[j][i][1] for j in xrange(N)]
			m=sorted(t)[len(t)//2]
			s+=sum(abs(i-m) for i in t)
		print s
	else:
		print 'Fegla Won'
