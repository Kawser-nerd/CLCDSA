import sys
T=int(raw_input())

def lca(a,b):
	for i in xrange(min(len(a),len(b))):
		if a[i]!=b[i]:
			return i
	return min(len(a),len(b))

def calc(a):
	s=1+len(a[0])
	for i in xrange(1,len(a)):
		s+=len(a[i])-lca(a[i],a[i-1])
	return s

def frac(a):
	if a==0:
		return 1
	return a*frac(a-1)

def dfs(a,m):
	if m==1:
		return calc(a),1
	ret,ways=-1,0
	for i in xrange(1,(1<<len(a))-1):
		p=[a[j] for j in xrange(len(a)) if ((1<<j)&i)!=0]
		q=[a[j] for j in xrange(len(a)) if ((1<<j)&i)==0]
		if len(q)>=m-1:
			t,s=dfs(q,m-1)
			t+=calc(p)
			if ret==-1 or ret<t:
				ret=t
				ways=s
			elif ret==t:
				ways+=s
	return ret,ways

for Case in xrange(1,T+1):
	M,N=map(int,raw_input().split())
	A=[raw_input() for i in xrange(M)]
	A.sort()
	a,b=dfs(A,N)
	print 'Case #%d:'%Case,a,b
	print >>sys.stderr,'Case #%d:'%Case,a,b
