f = open('C-small-attempt0.in','r')
x=f.readlines()
x=x[1:]
for i in range(len(x)/2):
	a=2*i
	x[a]=x[a].strip().split()
	x[a+1]=x[a+1].strip().split()
	n=x[a][0]
	l=int(x[a][1])
	h=int(x[a][2])
	ans = 0
	for z in range(l,h+1):
		cou=0
		for c in x[a+1]:
			if z%int(c)==0 or int(c)%z==0:
				cou+=1
		if cou==len(x[a+1]):
			ans=z
			break
	if ans==0:
		print "Case #%d: NO"%(i+1)
	else:
		print "Case #%d: %d"%(i+1,ans)
		

