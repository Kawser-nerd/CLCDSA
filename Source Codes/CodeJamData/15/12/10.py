#!/usr/bin/env python

for tc in range(int(input())):
	b,n=map(int,input().split())
	m=list(map(int,input().split()))
	l,r=-1,10**18
	while l+1<r:
		x=l+r+1>>1
		if sum(map(lambda t:x//t,m)) +b>=n:r=x
		else: l=x
	e=[]
	for j in range(b):
		e.append((-(r%m[j]),j))
		n-= r//m[j]
	e.sort()
	print("Case #%d: %d"%(tc+1,1+e[n-1][1]))
