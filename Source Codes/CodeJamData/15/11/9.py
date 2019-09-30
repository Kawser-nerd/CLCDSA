#!/usr/bin/env python

for tc in range(int(input())):
	n=int(input())
	m=list(map(int,input().split()))
	x,y,t,r=0,0,0,0
	for d in m:
		if d<t:
			x+=t-d
			r=max(r,t-d)
		t=d
	for d in m[:-1]:
		y+=min(r,d)
	print("Case #%d: %d %d"%(tc+1,x,y))
