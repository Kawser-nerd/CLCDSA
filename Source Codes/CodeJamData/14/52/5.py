#!/usr/bin/python


import sys


def gain(pgain, s_t,s_d,f_t, addm, g):
	lgain = pgain[ min(addm+f_t,1000) ]
	if s_d <= addm+s_t:
		sgain = pgain[ min(addm+s_t-s_d,1000) ] + g
		return max(lgain,sgain)
	return lgain


def solve(P, Q, N, H, G):
	H.reverse()
	G.reverse()
	pgain = [0 for i in range(1001)]
	for i in range(len(H)):
		h = H[i]
		g = G[i]
		s_t = (h-1)/Q
		s_d = ((h-1)%Q)/P+1
		f_t = (h-1)/Q+1
		cgain = [gain(pgain, s_t, s_d, f_t, i, g) for i in range(1001)]
		pgain = cgain
		#for i in range(1001):
	return pgain[1]

if __name__ == "__main__":
	T = int(sys.stdin.readline())

	for t in range(T):
		P, Q, N = map(int, sys.stdin.readline().split())
		H = []
		G = []
		for i in range(N):
			h,g = map(int, sys.stdin.readline().split())
			H.append(h)
			G.append(g)
		print "Case #{}: {}".format(t+1, solve(P, Q, N, H, G))
