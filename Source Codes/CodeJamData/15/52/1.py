import math
import re

def solve(n,k,sums):
	a = [0]*(n-k)
	r = [0]*k
	q = [0]*k
	for i in range(1,n-k+1):
		a[i-1] = sums[i-1]-sums[i]
	for i in range(k):
		b = [a[i+k*x] for x in range((n-1-i)/k)]
		for c in range(1,len(b)):
			b[c]=b[c-1]+b[c]
		b.append(0)
		d = abs(max(b)-min(b))
		r[i] = d
		q[i] = max(b)
	m = max(r)
	rem = (sums[0]-sum(q))%k
	n = m*k-sum(r)
	if n>=rem:
		return m
	else:
		return m+1

inp = open("B-large.in","r")
out = open("B-large","w")
lines = inp.readlines()
i=1
count=1
while i<len(lines):
	[n,k] = [int(x) for x in re.split(" ",lines[i])]
	B = [int(x) for x in re.split(" ",lines[i+1])]
	out.write("Case #"+str(count)+": "+"{:}".format(solve(n,k,B))+"\n")
	i+=2
	count+=1
out.close()
inp.close()

