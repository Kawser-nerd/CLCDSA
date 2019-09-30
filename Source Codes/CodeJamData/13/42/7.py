def ok1(x,y):
	if x==0:
		return 0
	return y/2+ok1((x-1)/2,y/2)
def ok2(x,y):
	if x==y-1:
		return 0
	return y/2+ok2((x+1)/2,y/2)
t=input()
for i in range(t):
	n,p=map(int,raw_input().split())
	ans1,ans2=0,2**n-1
	L,R=0,2**n-1
	while L<R:
		m=(L+R+1)/2
		if ok1(m,2**n)>=p:
			R=m-1
		else:
			L=m
	ans1=L
	L,R=0,2**n-1
	while L<R:
		m=(L+R+1)/2
		if ok2(m,2**n)<2**n-p:
			R=m-1
		else:
			L=m
	ans2=L
	print('Case #%d: %d %d'%(i+1,ans1,ans2))


