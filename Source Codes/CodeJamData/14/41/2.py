T=int(raw_input())

for Case in xrange(1,T+1):
	N,C=map(int,raw_input().split())
	A=map(int,raw_input().split())
	A.sort()
	s=0
	i=0
	j=N-1
	while i<=j:
		if i==j:
			s+=1
			break
		if A[i]+A[j]<=C:
			s+=1
			i+=1
			j-=1
		else:
			s+=1
			j-=1
	print 'Case #%d:'%Case,s
