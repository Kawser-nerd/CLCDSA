#!/usr/bin/python2.7

def work(K,N,P):
	return min(work_backspace(K,N,P), work_giveup(K,N,P))

def work_backspace(K,N,P):
	Pc = 1
	res = N*N
	for k in range(K+1):
		r = (K-k) # BS
		r += (N+1-k) # Retype
		r += (1 - Pc) * (N+1)
		if k < K:
			Pc *= P[k]
		res = min(res,r)
	return res

def work_giveup(K,N,P):
	return 1 + N + 1

T = int(raw_input())
for i in range(1,T+1):
	K,N = map(int,raw_input().split())
	P = map(float,raw_input().split())
	print('Case #{}: {:f}'.format(i, work(K,N,P)))
