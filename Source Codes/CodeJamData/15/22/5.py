#!/usr/bin/python

import sys
import numpy as np

def solve(R,C,N):
	mat = np.zeros((R+1,C+1), dtype=int)

	def brute(r,c,n, unsat):
		if c>C:
			return brute(r+1,1,n,unsat)
		if r>R:
			return unsat

		minunsat = np.inf
		if (r-1)*C+c + (N-n) <= R*C:
			mat[r,c] = 0
			minunsat = min(minunsat, brute(r,c+1,n,unsat))
		if n < N:
			mat[r,c] = 1
			minunsat = min(minunsat, brute(r,c+1,n+1,unsat+mat[r,c-1]+mat[r-1,c]))
		return minunsat

	return brute(1,1,0,0)

if __name__ == "__main__":
	T = int(sys.stdin.readline())

	for t in range(T):
		R,C,N = map(int, sys.stdin.readline().split())
		print "Case #{}: {}".format(t+1, solve(R,C,N))