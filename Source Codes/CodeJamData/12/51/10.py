fin=open("A-small-attempt0.in","r")
fout=open("A.out","w")
numcases=int(fin.readline())
numcases+=1
for cas in xrange(1,numcases):
	fout.write("Case #"+str(cas)+":")
	n=int(fin.readline())
	l=map(float,fin.readline().split())
	p=map(float,fin.readline().split())
	q=[p[i]/l[i] for i in xrange(n)]
	r=[(q[i],-i) for i in xrange(n)]
	r.sort()
	r.reverse()
	for i in r:
		fout.write(" "+str(-i[1]))
	fout.write("\n")
