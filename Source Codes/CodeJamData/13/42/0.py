def MyWorst(n,p):
	if p==0:
		return 0
	#I lose
	p2=max(0,(p-1)//2)
	return MyWorst(n-1,p2)+(1<<(n-1))
def MyBest(n,p):
	#print 'mybest',n,p
	if p==(1<<n)-1:
		return (1<<n)-1
	#I win
	p2=(1<<(n-1))-1-max(0,(((1<<n)-1-p)-1)//2)
	return MyBest(n-1,p2)

T=int(raw_input())
for case in xrange(T):
	print 'Case #%d:'%(case+1),
	N,P=map(int,raw_input().split())
	l=0
	r=(1<<N)
	while r-l>1:
		m=(l+r)>>1
		if MyWorst(N,m)<P:
			l=m
		else:
			r=m
	print l,
	l=0
	r=(1<<N)
	while r-l>1:
		m=(l+r)>>1
		if MyBest(N,m)<P:
			l=m
		else:
			r=m
	print l
