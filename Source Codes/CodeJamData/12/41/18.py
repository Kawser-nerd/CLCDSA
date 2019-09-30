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
	def solve():
		N = next(ints)
		D = (N+1)*[0]
		L = (N+1)*[0]
		K = (N+1)*[0]
		for i in range(N):
			D[i] = next(ints)
			L[i] = next(ints)
		D[N] = next(ints)
		K[0]=D[0]
		for i in range(N) :
			j=i+1
			#print(i,j)
			while j <= N and D[j]-D[i]<=K[i]:
				if j==N: return True
				K[j]=max(K[j],min(D[j]-D[i],L[j]))
				j+=1
				#print(i,j)
		return False
	
	if solve():
		print("Case #",t+1,": YES",sep='')
	else:
		print("Case #",t+1,": NO",sep='')
