T=int(raw_input())
for Case in xrange(T):
	A,B,K=map(int,raw_input().split())
	def tobin(x):
		return [(x>>(31-i))&1 for i in xrange(32)]
	A,B,K=map(tobin,[A-1,B-1,K-1])
	dp=[[[[int(i==1 and j==1 and k==1) for i in xrange(2)] for j in xrange(2)] for k in xrange(2)]]
	#print A,B,K
	for i in xrange(32):
		new=[[[0 for z in xrange(2)] for j in xrange(2)] for k in xrange(2)]
		for j in xrange(2):
			for k in xrange(2):
				for l in xrange(2):
					for m in xrange(2):
						for n in xrange(2):
							if dp[-1][j][k][l]==0:
								continue
							o=m&n
							if j==1 and m>A[i]:
								continue
							if k==1 and n>B[i]:
								continue
							if l==1 and o>K[i]:
								continue
							nj=int(j==1 and m==A[i])
							nk=int(k==1 and n==B[i])
							nl=int(l==1 and o==K[i])
							#print j,k,l,nj,nk,nl
							new[nj][nk][nl]+=dp[-1][j][k][l]
		#print new
		dp.append(new)
	print 'Case #%d:'%(Case+1),sum(i for j in dp[-1] for k in j for i in k)
