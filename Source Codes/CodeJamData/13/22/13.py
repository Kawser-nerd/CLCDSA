fin=open("B-large.in")
fout=open("B.out",'w')
numtests=int(fin.readline())
fact=[1 for i in xrange(6000)]
for i in xrange(1,6000):
	fact[i]=i*fact[i-1]
def C(a,b):
	return fact(a)/fact(a-b)/fact(b)
for cas in xrange(1,numtests+1):
	fout.write("Case #"+str(cas)+": ")
	n,x,y=map(int,fin.readline().split())
	m=abs(x)+abs(y)
	curr=(m-1)*(m)/2
	nex=(m+1)*(m+2)/2
	on=nex-curr
	if n>=nex:
		fout.write("1\n")
		continue
	if n<=curr:
		fout.write("0\n")
		continue
	di=n-curr
	h=abs(y)
	p=[[0.0 for i in xrange(m+1)]for j in xrange(m+1)]
	if h==m:
		fout.write("0\n")
		continue
	for i in xrange(m+1):
		p[i][0]=p[0][i]=0.5**i
	for i in xrange(1,m):
		for j in xrange(1,m):
			p[i][j]=(p[i-1][j]+p[i][j-1])/2
	for i in xrange(1,m):
		p[m][i]=p[i][m]=p[i-1][m]+p[i][m-1]/2
	p[m][m]=1.0
	#print cas,p
	ans=0.0
	t=min(di,m)
	s=di-t
	while(s<=m and t>=h+1):
		#print s,t,h
		ans+=p[s][t]
		s+=1
		t-=1
	fout.write(str(ans)+"\n")


fin.close()
fout.close()
