import sys
T=int(raw_input())
fin=open('C.data','r')
data={}
prob={}
for line in fin:
	fields=map(int,line.split())
	m={}
	for j in xrange(2,len(fields),2):
		m[fields[j]]=fields[j+1]
	data[fields[0]]=m
	prob[fields[0]]=fields[1]
def good(m,p):
	s=1
	for i in p:
		if i not in m:
			return 0
		s*=m[i]
	return s
for case in xrange(T):
	print 'Case #%d:'%(case+1)
	R,N,M,K=map(int,raw_input().split())
	for r in xrange(R):
		ps=map(int,raw_input().split())
		best=0
		s=0
		for i,j in data.iteritems():
			g=float(good(j,ps))/float(prob[i])
			s+=g
			#if g!=0:
				#print i,g
			if g>best:
				best=g
				you=i
		#break
		print >>sys.stderr,best,s,best/s
		print you
