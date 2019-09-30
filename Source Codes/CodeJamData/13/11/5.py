T=int(raw_input())
def area(r,ncircle):
	#sum(2*r+1,2*r+5,...,2*r+4*(ncircle)-3)
	return ((2*r+1)+(2*r+4*(ncircle)-3))*ncircle/2
for case in xrange(T):
	print 'Case #%d:'%(case+1),
	r,t=map(int,raw_input().split())
	low=1
	high=10000000000000000
	while high-low>1:
		mid=(low+high)//2
		#print 'area',r,mid,area(r,mid)
		if area(r,mid)<=t:
			low=mid
		else:
			high=mid
	print low
