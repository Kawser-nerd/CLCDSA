#!/usr/bin/python


import sys

def solve(N, p, q, r, s):
	A = []
	S = []
	psum = 0
	for i in range(N):
		a = s+((i*p+q) % r)
		A.append(a)
		psum = psum + a
		S.append(psum)

	'''mingain = psum
	for i in range(N):
		for j in range(i+1):
			gain = max(S[j],S[i]-S[j],psum-S[i])
			mingain = min(mingain,gain)
	return float(psum-mingain)/psum'''

	mingain = psum
	minpgain = psum

	hpi = 0
	for i in range(N):
		j = hpi
		while j <= i:
			pgain = max(S[j], S[i]-S[j]) 
			gain = max(S[j], S[i]-S[j], psum-S[i])
			mingain = min(mingain, gain)
			if 2*S[j] > S[i]:
				break
			if pgain <= minpgain:
				hpi = j
			j = j+1
	return float(psum-mingain)/psum

if __name__ == "__main__":
	T = int(sys.stdin.readline())

	for t in range(T):
		N, p, q, r, s = map(int, sys.stdin.readline().split())
		print "Case #{}: {}".format(t+1, solve(N, p, q, r, s))
