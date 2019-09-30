from __future__ import print_function
import sys
from sys import stdin


def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)


def ln(f=int):
	return list(map(f,stdin.readline().strip().split()))

T, = ln()
INF = float('inf')

for test in range(T):
	s,K = ln(str)
	K = int(K)
	s = [0 if c=="+" else 1 for c in s]

	best = 0
	for i in range(len(s)-K+1):
		if s[i]!= 0:
			for j in range(i,i+K):
				s[j] ^= 1
			best+=1
	
	if sum(s) != 0:
		best = "IMPOSSIBLE"

	print ("Case #" + str(test+1) + ": " + str(best))


