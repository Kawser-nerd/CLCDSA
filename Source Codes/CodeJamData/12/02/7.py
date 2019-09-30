#!/usr/bin/python3

import sys

def gethighest(t):
	# [0,10] inclusive!!
	n,k = t//3,t%3
	if n == 0:
		return min(1,k),k
	elif n == 10:
		return 10,10
	elif n == 9:
		return n+(k!=0), 10
	else:
		return n+(k!=0), n+1+(k==2)

def work(s):
	s = list(map(int,s.split()))
	N = s[0] # Number of persons
	S = s[1] # Surprises
	p = s[2] # Threshold (>=)
	T = s[3:]
	assert(len(T) == N)

	BH = 0 # Both >= p
	OH = 0 # One >= p
	BL = 0 # Both < p

	for t in T:
		nh, sh = gethighest(t)
		if nh >= p:
			BH += 1
		elif sh >= p:
			OH += 1
		else:
			BL += 1

	return (BH + min(OH,S))

if __name__ == '__main__':
	T = int(sys.stdin.readline().strip())
	for i in range(T):
		s = work(sys.stdin.readline().rstrip())
		print('Case #{}: {}'.format(i+1, s))
