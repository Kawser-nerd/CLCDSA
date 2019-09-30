#!/usr/bin/env python3

import sys
def get_ints():
	for line in sys.stdin:
		for word in line.split():
			yield int(word)
	return
ints = get_ints()

def get_floats():
	for line in sys.stdin:
		for word in line.split():
			yield float(word)
	return
floats = get_floats()

def up(a):
	i = 1
	while i<a:
		i*=2
	return 2*i


T = next(ints)
for t in range(T):
	N = next(ints)
	W = next(ints)
	L = next(ints)
	R = N*[None]
	for i in range(N):
		a = next(ints)
		R[i]=(a,i)
	R.sort()
	pos=N*[None]
	lanes=[]
	clane=[0,W,0]
	while R:
		(r,p) = R.pop()
		#print(lanes,clane,(r,p))
		while 1:
			if clane[2]<=L: break
			clane=lanes.pop()
		lup=up(r)
		if clane[1]>clane[0]+lup:
			lanes.append([clane[0]+lup,clane[1],clane[2]])
			clane[1]=clane[0]+lup
		pos[p]=[clane[0],clane[2]]
		clane[2]+=2*r
	print("Case #",t+1,":",sep='', end='')
	for i in range(N):
		#print('',pos[i],end='')
		print('',pos[i][0],pos[i][1],end='')
	print()
