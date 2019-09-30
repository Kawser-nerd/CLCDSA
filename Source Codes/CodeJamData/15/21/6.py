#!/usr/bin/python

import sys

def comb(N):
	s = 0
	for i in N:
		s = 10*s + i
	return s

def decomb(n):
	N = []
	while n > 0:
		N.append(n%10)
		n = n/10
	N.reverse()
	return N

def sub(N):
	return decomb(comb(N)-1)

def solve(N):
	if N[-1] == 0:
		return 1+solve(sub(N))
	step = 1
	l = len(N)
	if l > 1:
		step = solve([9 for i in range(l-1)]) + 1
	step += comb(reversed(N[:l/2])) + comb((N[l/2:])) - 1 + 1
	if sum(N[:l/2]) <= 1:
		step -= 1
	return step

if __name__ == "__main__":
	T = int(sys.stdin.readline())

	for t in range(T):
		n = int(sys.stdin.readline())

		# Nl = [int(c) for c in Ns.strip()]
		print "Case #{}: {}".format(t+1, solve(decomb(n)))