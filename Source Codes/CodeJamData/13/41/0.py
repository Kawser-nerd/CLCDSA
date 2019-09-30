T=int(raw_input())

def cost(e,b):
	#print 'N e b',N,e,b,(N+N-(e-b)+1)*(e-b)//2
	return (N+N-(e-b)+1)*(e-b)//2
for case in xrange(1,T+1):
	print 'Case #%d:'%case,
	N,M=map(int,raw_input().split())
	events=[]
	original=0
	for i in xrange(M):
		b,e,p=map(int,raw_input().split())
		events.append((b,0,p))
		events.append((e,1,p))
		original+=p*cost(e,b)
	events.sort()
	tickets=[]
	mincost=0
	for timepoint,etype,amount in events:
		if etype==0:
			tickets.append([timepoint,amount])
		else:
			s=amount
			while s>0:
				if tickets[-1][1]==0:
					tickets.pop()
				t=min(tickets[-1][1],s)
				s-=t
				tickets[-1][1]-=t
				mincost+=t*cost(timepoint,tickets[-1][0])
	#print original,mincost
	print (original-mincost)%1000002013
