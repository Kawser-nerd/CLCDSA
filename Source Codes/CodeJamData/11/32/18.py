T=int(raw_input())
for repeat in xrange(T):
	data=raw_input().split()
	L=int(data[0])
	t=int(data[1])
	N=int(data[2])
	C=int(data[3])
	a=[]
	for i in xrange(4,4+C):
		a+=[int(data[i])]
	circlesum=0
	for i in xrange(len(a)):
		circlesum+=a[i]
	#print "circlesum: %d" %circlesum
	disset=[]
	for i in xrange(len(a)):
		disset+=[N/C]
		if i<N%C: disset[i]+=1
	#print disset
	totaltime=0
	for i in xrange(len(a)):
		totaltime+=a[i]*disset[i]*2
	if t>=totaltime:
		#boosters cannot be finished
		print "Case #%d: %d" %(repeat+1, totaltime)
		continue
	#position when the boosters are built
	passed=t/circlesum/2
	#print "passed: %d" %passed
	for i in xrange(len(disset)):
		disset[i]-=passed
	timeleft=t-circlesum*passed*2
	for stopi in xrange(len(a)):
		timeleft-=a[stopi]*2
		disset[stopi]-=1
		if timeleft<=0: break
	disout=-timeleft/2
	if disout>0:
		a+=[disout]
		disset+=[1]
	j=0
	while j<len(a):
		if disset[j]==0:
			del(a[j])
			del(disset[j])
		j+=1
	#print a
	#print disset
	#new lists built
	totaltime=t
	while L>0 and len(a)>0:
		imax=0
		for i in xrange(len(a)):
			if a[imax]<a[i]: imax=i
		if L>=disset[imax]:
			totaltime+=disset[imax]*a[imax]
			L-=disset[imax]
			#disset[imax]=0
			del(a[imax])
			del(disset[imax])
		else:
			totaltime+=L*a[imax]
			disset[imax]-=L
			L=0
	#print a
	#print disset
	#print totaltime
	for i in xrange(len(a)):
		totaltime+=2*a[i]*disset[i]
	print "Case #%d: %d" %(repeat+1,totaltime)