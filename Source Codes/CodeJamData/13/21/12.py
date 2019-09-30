fin=open("A-large.in")
fout=open("A.out",'w')
numtests=int(fin.readline())
for cas in xrange(1,numtests+1):
	fout.write("Case #"+str(cas)+": ")
	a,n=map(int,fin.readline().split())
	s=map(int,fin.readline().split())
	s.sort()
	cost=[0 for i in xrange(n+1)]
	if a==1:
		fout.write(str(n)+"\n")
		continue
	for i in xrange(n):
		cost[i+1]=cost[i]
		if(s[i]<a):
			a+=s[i]
			continue
		while(a<=s[i]):
			a=2*a-1
			cost[i+1]+=1
		a+=s[i]
	t=[cost[i]+(n-i) for i in xrange(n+1)]
	fout.write(str(min(t))+"\n")
fin.close()
fout.close()
