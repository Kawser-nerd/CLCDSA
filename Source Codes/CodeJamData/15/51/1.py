import math
import re

def solve(n,d,s0,a_s,cs,rs,m0,am,cm,rm):
	s = [s0]*n
	m = [m0]*n
	for i in range(1,n):
		s[i]=(s[i-1]*a_s+cs)%rs
		m[i]=(m[i-1]*am+cm)%rm
	for i in range(1,n):
		m[i]=m[i]%i
	r = [(s[0],s[0])]*n
	for i in range(1,n):
		(a,b) = r[m[i]]
		c = s[i]
		if c<a:
			r[i] = (c,b)
		elif b<c:
			r[i] = (a,c)
		else:
			r[i] = (a,b)
	r1 = [x[0] for x in r if x[1]-x[0]<=d]
	r2 = [x[1] for x in r if x[1]-x[0]<=d]
	r1.sort()
	r2.sort()
	a = 0
	b = 0
	i = 0
	j = 0
	while i<len(r2):
		top = r2[i]
		while i<len(r2) and r2[i]==top:
			i+=1
			a+=1
		while j<len(r1) and r1[j]<top-d:
			j+=1
			a-=1
		b = max(b,a)
	return b

inp = open("A-large.in","r")
out = open("A-large","w")
lines = inp.readlines()
i=1
count=1
while i<len(lines):
	print count
	A = [int(x) for x in re.split(" ",lines[i])]
	B = [int(x) for x in re.split(" ",lines[i+1])]
	C = [int(x) for x in re.split(" ",lines[i+2])]
	out.write("Case #"+str(count)+": "+"{:}".format(solve(A[0],A[1],B[0],B[1],B[2],B[3],C[0],C[1],C[2],C[3]))+"\n")
	i+=3
	count+=1
out.close()
inp.close()

